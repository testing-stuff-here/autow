(function($){
  
  MutationObserver = window.MutationObserver || window.WebKitMutationObserver;
  
  var currentPath = location.pathname;
  
  FastButton = function(element, iconSibling){
    this.element = element;    
    this.iconSibling = (typeof iconSibling != 'undefined') ? iconSibling : false;  
    element.addEventListener('touchstart', this, false);
    element.addEventListener('click', this, false);
  }

  
  FastButton.prototype.handleEvent = function(event){    
    switch (event.type) {
      case 'touchstart' : this.onTouchStart(event) ; break;
      case 'touchmove' : this.onTouchMove(event) ; break;
      case 'touchend' : this.onEnd(event) ; break;
      case 'click' : this.onClick(event) ; break;
    }
  }
  
  FastButton.prototype.onClick = function(event) {
    var clickElement = $(this.element);
    if(this.iconSibling != false){
      clickElement = iconSibling;
    }
    clickElement.removeClass('click-transition').removeClass('click-transition-2');
  }
  
  FastButton.prototype.onTouchStart = function(event) {
    var d = new Date();
    this.startTouch = d.getTime();
    this.element.addEventListener('touchend', this, false);
    document.body.addEventListener('touchmove', this, false);
    
    this.startX = event.touches[0].clientX;
    this.startY = event.touches[0].clientY;
    
  }
  
  // When the touchmove event is invoked, check if the user has dragged past the threshold of 10px
  FastButton.prototype.onTouchMove = function(event) {
    if(Math.abs(event.touches[0].clientX - this.startX) > 10 ||
       Math.abs(event.touches[0].clientY - this.startY) > 10) {
      this.reset();
    }
  }
  
  FastButton.prototype.onEnd = function(event) {    

    event.stopPropagation();
    this.reset();
    var d = new Date();
    var endTouch = d.getTime();
    var duration = endTouch - this.startTouch;
    var iconSibling = this.iconSibling;
    if(duration > 200){
      if(iconSibling !== false){
        if(iconSibling.hasClass('ui-icon-checkbox-off')){
          iconSibling.addClass('click-transition').removeClass('click-transition-2');
        }
        else if (iconSibling.hasClass('ui-icon-checkbox-on')){
          iconSibling.addClass('click-transition-2').removeClass('click-transition');
        }
      }
      else {
        var jElement = $(this.element);
        if(jElement.hasClass('ui-checkbox-off')){      
          jElement.addClass('click-transition').removeClass('click-transition-2');
          setTimeout(function(){
            iconSibling.removeClass('click-transition');
          }, 3000);    
        }
        else if(jElement.hasClass('ui-checkbox-on')){      
          jElement.addClass('click-transition-2').removeClass('click-transition');
          setTimeout(function(){
            iconSibling.removeClass('click-transition-2');
          }, 3000);
        }
      }
    }
  }
  
  FastButton.prototype.reset = function() {
    this.element.removeEventListener('touchend', this, false);
    document.body.removeEventListener('touchmove', this, false);
  }
  
  $(document).delegate(".ui-dialog", "pageinit", function(){
    $('.ui-dialog .ui-header a').on("touchstart", function(event){
      $(this).addClass('blue-glow');
    });
    var attachDialogCloseEvent = function(){
      $('.ui-dialog .ui-header a').on("touchstart",function(event){
        
      });
      $('.ui-dialog .ui-header a').on("click", function(event){
        event.preventDefault();
        event.stopPropagation();
        event.stopImmediatePropagation(); 
        $.mobile.changePage(currentPath, {allowSamePageTransition:true, transition:"slideup", changeHash:true, reverse:true});
      });
    }
    attachDialogCloseEvent();
    
    $(document).on("touchstart", function(e){
      

      var startX = event.touches[0].clientX;
      var startY = event.touches[0].clientY;
      var startTouch;
      
      if($(e.target).hasClass('ui-btn') && ($(e.target).hasClass('ui-checkbox-off') || $(e.target).hasClass('ui-checkbox-on'))){
        
        FastEvent = function(element, iconSibling){
          this.element = element;    
          this.iconSibling = (typeof iconSibling != 'undefined') ? iconSibling : false;
          var d = new Date();
          startTouch = d.getTime();
          this.startTouch = startTouch;
          //element.addEventListener('touchmove', this, false);
          document.body.addEventListener('touchmove', this, false);
          element.addEventListener('touchend', this, false);
          element.addEventListener('click', this, false);
        }

  
        FastEvent.prototype.handleEvent = function(event){    
          switch (event.type) {
            case 'touchstart' : this.onTouchStart(event) ; break;
            case 'touchmove' : this.onTouchMove(event) ; break;
            case 'touchend' : this.onEnd(event) ; break;
            case 'click' : this.onClick(event) ; break;
          }
        }
  
        FastEvent.prototype.onClick = function(event) {
          var clickElement = $(this.element);
          if(this.iconSibling != false){
            clickElement = iconSibling;
          }
          clickElement.removeClass('click-transition').removeClass('click-transition-2');
        }
  
        // When the touchmove event is invoked, check if the user has dragged past the threshold of 10px
        FastEvent.prototype.onTouchMove = function(event) {
          if(Math.abs(event.touches[0].clientX - startX) > 10 ||
             Math.abs(event.touches[0].clientY - startY) > 10) {
            this.reset();
          }          
        }
  
        FastEvent.prototype.onEnd = function(event) {    

          event.stopPropagation();
          this.reset();
          var d2 = new Date();
          var endTouch = d2.getTime();
          var duration = endTouch - this.startTouch;
          var iconSibling = this.iconSibling;
          if(duration > 70){
            if(iconSibling !== false){
              if(iconSibling.hasClass('ui-icon-checkbox-off')){
                iconSibling.addClass('click-transition').removeClass('click-transition-2');
                setTimeout(function(){
                  iconSibling.removeClass('click-transition');
                }, 3000);
              }
              else if (iconSibling.hasClass('ui-icon-checkbox-on')){
                iconSibling.addClass('click-transition-2').removeClass('click-transition');
                setTimeout(function(){
                  iconSibling.removeClass('click-transition-2');
                }, 3000);
              }
            }
            else {
              var jElement = $(this.element);
              if(jElement.hasClass('ui-checkbox-off')){      
                jElement.addClass('click-transition').removeClass('click-transition-2');    
              }
              else if(jElement.hasClass('ui-checkbox-on')){      
                jElement.addClass('click-transition-2').removeClass('click-transition');
              }
            }
          }
        }
  
        FastEvent.prototype.reset = function() {
          this.element.removeEventListener('touchend', this, false);
          document.body.removeEventListener('touchmove', this, false);
        }
        
        new FastEvent(e.target);
      }
    });
    
    var addEventsOnMutation = function(){
      $('.ui-dialog li a.ui-btn').each(function(i,e){
        new FastButton(e);
      });
      
      // If using 1.3.2 jQuery Mobile
      $('.ui-dialog li.ui-btn a').each(function(i,e){
        var iconSibling = $(e).parent().siblings('.ui-icon');
        new FastButton(e, iconSibling);
      });
    }
    
    
    var target = $('.ui-dialog')[0];    
    var observer = new MutationObserver(function(mutations, observer){
      //addEventsOnMutation();
    });    
    observer.observe(target, {
      subtree: true,
      attributes: true,
      childList: true,
      characterData: true,
    });    
    
    
    var uiDialogTarget = $('.ui-dialog');
  
    var uiDialogObserver = new MutationObserver(function(mutations, observer){
      attachDialogCloseEvent();
    });
  
    if(uiDialogTarget.length){
      uiDialogTarget.each(function(i,e){
        uiDialogObserver.observe(e, {
          subtree: true,
          attributes: true,
          childList: true,
          characterData: true,
        });
      });
    }
  });
  
  
  $(document).ready(function(){
    
    var addPopUpEventListener = function(){
      $('.ui-popup-container li a.ui-btn').each(function(i,e){
        new FastButton(e);
      });
      
      // If using 1.3.2 jQuery Mobile
      $('.ui-popup-container li.ui-btn a').each(function(i,e){
        var iconSibling = $(e).parent().siblings('.ui-icon');
        new FastButton(e, iconSibling);
      });
    }
    addPopUpEventListener();
    
    var addPopUpEventListenerActive = function(){
      $('.ui-popup-container.ui-popop-active li a.ui-btn').each(function(i,e){
        new FastButton(e);
      });
      
      // If using 1.3.2 jQuery Mobile
      $('.ui-popup-container.ui-popup-active li.ui-btn a').each(function(i,e){
        var iconSibling = $(e).parent().siblings('.ui-icon');
        new FastButton(e, iconSibling);
      });
    }    
    
    popTarget = $('.ui-page-active')[0];
    
    var popObserver = new MutationObserver(function(mutations, observer){
      addPopUpEventListenerActive();
    });
    

    popObserver.observe(popTarget, {
      subtree: true,
      attributes: true,
      childList: true,
      characterData: true,
    });

  });
  
  

})(jQuery);