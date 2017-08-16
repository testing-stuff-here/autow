﻿package htmlelements
{
	import flash.display.Sprite;
	import flash.events.*;
	import flash.net.NetConnection;
	import flash.net.NetStream;
	import flash.media.Video;
	import flash.media.SoundTransform;
	import flash.utils.Timer;

	import FlashMediaElement;
	import HtmlMediaEvent;

	public class VideoElement extends Sprite implements IMediaElement 
	{
		private var _currentUrl:String = "";
		private var _autoplay:Boolean = true;
		private var _preload:String = "";

		private var _connection:NetConnection;
		private var _stream:NetStream;
		private var _video:Video;
		private var _element:FlashMediaElement;
		private var _soundTransform;
		private var _oldVolume:Number = 1;

		// event values
		private var _duration:Number = 0;
		private var _framerate:Number;
		private var _isPaused:Boolean = true;
		private var _isEnded:Boolean = false;
		private var _volume:Number = 1;
		private var _isMuted:Boolean = false;

		private var _bytesLoaded:Number = 0;
		private var _bytesTotal:Number = 0;
		private var _bufferedTime:Number = 0;
		private var _bufferEmpty:Boolean = false;

		private var _videoWidth:Number = -1;
		private var _videoHeight:Number = -1;

		private var _timer:Timer;

		private var _isRTMP:Boolean = false;
		private var _isConnected:Boolean = false;
		private var _playWhenConnected:Boolean = false;
		private var _hasStartedPlaying:Boolean = false;

		public function get video():Video {
			return _video;
		}

		public function get videoHeight():Number {
			return _videoHeight;
		}

		public function get videoWidth():Number {
			return _videoWidth;
		}


		public function duration():Number {
			return _duration;
		}

		public function currentTime():Number {
			if (_stream != null) {
				return _stream.time;
			} else {
				return 0;
			}
		}

		// (1) load()
		// calls _connection.connect(); 
		// waits for NetConnection.Connect.Success
		// _stream gets created


		public function VideoElement(element:FlashMediaElement, autoplay:Boolean, preload:String, timerRate:Number, startVolume:Number) 
		{
			_element = element;
			_autoplay = autoplay;
			_volume = startVolume;
			_preload = preload;

			_video = new Video();
			addChild(_video);

			_connection = new NetConnection();
			_connection.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler);
			_connection.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
			//_connection.connect(null);

			_timer = new Timer(timerRate);
			_timer.addEventListener("timer", timerHandler);

		}

		private function timerHandler(e:TimerEvent) {

			_bytesLoaded = _stream.bytesLoaded;
			_bytesTotal = _stream.bytesTotal;

			if (!_isPaused)
				sendEvent(HtmlMediaEvent.TIMEUPDATE);

			trace("bytes", _bytesLoaded, _bytesTotal);

			if (_bytesLoaded < _bytesTotal)
				sendEvent(HtmlMediaEvent.PROGRESS);
		}

		// internal events
		private function netStatusHandler(event:NetStatusEvent):void {
			trace("netStatus", event.info.code);

			switch (event.info.code) {

				case "NetStream.Buffer.Empty":
					_bufferEmpty = true;
					_isEnded ? sendEvent(HtmlMediaEvent.ENDED) : null;
					break;

				case "NetStream.Buffer.Full":
					_bytesLoaded = _stream.bytesLoaded;
					_bytesTotal = _stream.bytesTotal;
					_bufferEmpty = false;

					sendEvent(HtmlMediaEvent.PROGRESS);
					break;

				case "NetConnection.Connect.Success":
					connectStream();
					break;
				case "NetStream.Play.StreamNotFound":
					trace("Unable to locate video");
					break;

				// STREAM
				case "NetStream.Play.Start":
					_isPaused = false;
					sendEvent(HtmlMediaEvent.LOADEDDATA);
					sendEvent(HtmlMediaEvent.CANPLAY);
					sendEvent(HtmlMediaEvent.PLAY);
					sendEvent(HtmlMediaEvent.PLAYING);
					_timer.start();
					break;

				case "NetStream.Seek.Notify":
					sendEvent(HtmlMediaEvent.SEEKED);
					break;

				case "NetStream.Pause.Notify":
					_isPaused = true;
					sendEvent(HtmlMediaEvent.PAUSE);
					break;

				case "NetStream.Play.Stop":
					_isEnded = true;
					_isPaused = false;
					_timer.stop();
					_bufferEmpty ? sendEvent(HtmlMediaEvent.ENDED) : null;
					break;

			}
		}


		private function securityErrorHandler(event:SecurityErrorEvent):void {
			trace("securityErrorHandler: " + event);
		}

		private function asyncErrorHandler(event:AsyncErrorEvent):void {
			// ignore AsyncErrorEvent events.
		}


		private function onMetaDataHandler(info:Object):void {
			_duration = info.duration;
			_framerate = info.framerate;
			_videoWidth = info.width;
			_videoHeight = info.height;

			// set size?

			sendEvent(HtmlMediaEvent.LOADEDMETADATA);
		}




		// interface members
		public function setSrc(url:String):void {
			if (_isConnected && _stream) {
				// stop and restart
				_stream.pause();				
			}

			_currentUrl = url;
			_isRTMP = !!_currentUrl.match(/^rtmp(s|t|e|te)?\:\/\//);
			_isConnected = false;
			_hasStartedPlaying = false;		
		}

		public function load():void {
			// disconnect existing stream and connection
			if (_isConnected && _stream) {
				_stream.pause();
				_stream.close();
				_connection.close();
			}
			_isConnected = false;

			// start new connection
			if (_isRTMP) {
				_connection.connect(_currentUrl.replace(/\/[^\/]+$/,"/"));
			} else {
				_connection.connect(null);
			}
			
			// in a few moments the "NetConnection.Connect.Success" event will fire
			// and call createConnection which finishes the "load" sequence
			sendEvent(HtmlMediaEvent.LOADSTART);
		}
		

		private function connectStream():void {
			trace("connectStream");
			_stream = new NetStream(_connection);
					
			// explicitly set the sound since it could have come before the connection was made
			_soundTransform = new SoundTransform(_volume);
			_stream.soundTransform = _soundTransform;						
			
			_stream.addEventListener(NetStatusEvent.NET_STATUS, netStatusHandler); // same event as connection
			_stream.addEventListener(AsyncErrorEvent.ASYNC_ERROR, asyncErrorHandler);

			var customClient:Object = new Object();
			customClient.onMetaData = onMetaDataHandler;
			_stream.client = customClient;

			_video.attachNetStream(_stream);
			
			// start downloading without playing )based on preload and play() hasn't been called)
			// I wish flash had a load() command to make this less awkward
			if (_preload != "none" && !_playWhenConnected) {
				_stream.play(_currentUrl, 0, 0);
				
				_stream.pause();
				_isPaused = true;
				sendEvent(HtmlMediaEvent.PAUSE); // have to send this because the "playing" event gets sent via event handlers
			}			

			_isConnected = true;

			if (_playWhenConnected && !_hasStartedPlaying) {
				play();
				_playWhenConnected = false;
			}

		}		

		public function play():void {

			if (!_hasStartedPlaying && !_isConnected) {
				_playWhenConnected = true;
				load();
				return;
			}

			if (_hasStartedPlaying) {
				if (_isPaused) {
					_stream.resume();
					_timer.start();
					_isPaused = false;
					sendEvent(HtmlMediaEvent.PLAY);
					sendEvent(HtmlMediaEvent.PLAYING);
				}
			} else {

				if (_isRTMP) {
					_stream.play(_currentUrl.split("/").pop());
				} else {
					_stream.play(_currentUrl);
				}
				_timer.start();
				_isPaused = false;
				_hasStartedPlaying = true;
				
				// don't toss play/playing events here, because we haven't sent a 
				// canplay / loadeddata event yet. that'll be handled in the net
				// event listener
			}

		}

		public function pause():void {
			if (_stream == null)
				return;

			_stream.pause();
			_isPaused = true;
			
			if (_bytesLoaded == _bytesTotal) {
				_timer.stop();
			}

			_isPaused = true;
			sendEvent(HtmlMediaEvent.PAUSE);
		}

		public function stop():void {
			if (_stream == null)
				return;

			_stream.close();
			_isPaused = false;
			_timer.stop();
			sendEvent(HtmlMediaEvent.STOP);
		}

		public function setCurrentTime(pos:Number):void {
			if (_stream == null)
				return;
			
			sendEvent(HtmlMediaEvent.SEEKING);
			_stream.seek(pos);
			sendEvent(HtmlMediaEvent.TIMEUPDATE);
		}

		public function setVolume(volume:Number):void {
			if (_stream != null) {
				_soundTransform = new SoundTransform(volume);
				_stream.soundTransform = _soundTransform;				
			}
			
			_volume = volume;

			_isMuted = (_volume == 0);

			sendEvent(HtmlMediaEvent.VOLUMECHANGE);
		}


		public function setMuted(muted:Boolean):void {

			if (_isMuted == muted)
				return;

			if (muted) {
				_oldVolume = (_stream == null) ? _oldVolume : _stream.soundTransform.volume;
				setVolume(0);
			} else {
				setVolume(_oldVolume);
			}

			_isMuted = muted;
		}


		private function sendEvent(eventName:String) {

			// calculate this to mimic HTML5
			_bufferedTime = _bytesLoaded / _bytesTotal * _duration;

			// build JSON
			var values:String = 
							"duration:" + _duration + 
							",framerate:" + _framerate + 
							",currentTime:" + (_stream != null ? _stream.time : 0) + 
							",muted:" + _isMuted + 
							",paused:" + _isPaused + 
							",ended:" + _isEnded + 
							",volume:" + _volume +
							",src:\"" + _currentUrl + "\"" +
							",bytesTotal:" + _bytesTotal +
							",bufferedBytes:" + _bytesLoaded +
							",bufferedTime:" + _bufferedTime +
							",videoWidth:" + _videoWidth +
							",videoHeight:" + _videoHeight +
							"";

			_element.sendEvent(eventName, values);
		}
	}
}