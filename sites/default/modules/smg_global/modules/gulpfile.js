"use strict";

let gulp = require('gulp');
let babel = require('gulp-babel');
let sass = require('gulp-sass');
let sourcemaps = require('gulp-sourcemaps');
let cleanCSS = require('gulp-clean-css');
let rename = require('gulp-rename');
let notify = require('gulp-notify');
let autoprefixer = require('gulp-autoprefixer');
let uglify = require('gulp-uglify');
let concat = require('gulp-concat');
let iife = require('gulp-iife');
let replace = require('gulp-replace');

gulp.task('purf:sass', () => {
  return gulp.src('./smg_pop_up/sass/**/*.scss', {base: './'})
    .pipe(sourcemaps.init())
    .pipe(
      sass({})
        .on('error', notify.onError((er) => er))
    )
    .pipe(autoprefixer({ browsers: ['> 1%', 'last 2 versions', 'Firefox ESR', 'IE 9'] }))
    .pipe(sourcemaps.write('.'))
    .pipe(rename((path) => { path.dirname += '/../css' }))
    .pipe(gulp.dest('.'))
    .pipe(rename((path) => { path.dirname += '/../css' }))
    .pipe(notify({ message: 'PURF SASS Compiled' }));
});

gulp.task('purf:css:minify', () => {
  return gulp.src(['./smg_pop_up/css/**/*.css', '!./smg_pop_up/css/**/*.min.css'], {base: './'})
    .pipe(cleanCSS())
    .pipe(rename({ suffix: '.min' }))
    .pipe(gulp.dest('.'))
});

gulp.task('purf:sass:watch', () => {
  gulp.watch('./smg_pop_up/sass/**/*.scss', ['purf:sass']);
  gulp.watch(['./smg_pop_up/css/**/*.css', '!./smg_pop_up/css/**/*.min.css'], ['purf:css:minify']);
});

gulp.task('purf:sass:all', ['purf:sass', 'purf:css:minify', 'purf:sass:watch']);

gulp.task('purf:js', () => {
  return gulp.src(['./smg_pop_up/js/purf-object.js', './smg_pop_up/js/purf.js', './smg_pop_up/js/ctools-override.js'], {base: './'})
    .pipe(sourcemaps.init())
    .pipe(babel({ presets: ['es2015'] }))
    .pipe(concat('smg-pop-up.js'))
    .pipe(iife({ useStrict: false }))
    .pipe(gulp.dest('./smg_pop_up/js'))
    .pipe(rename('smg-pop-up.min.js'))
    .pipe(uglify())
    .pipe(gulp.dest('./smg_pop_up/js'));
});

gulp.task('leadership-angular:js', () => {
  return gulp.src(['./leadership/angular/src/**/*.js'])
    .pipe(sourcemaps.init())
    .pipe(babel({ presets: ['es2015'] }))
    .pipe(iife({ useStrict: false }))
    .pipe(gulp.dest('./leadership/angular/js'))
    .pipe(rename({ suffix: '.min' }))
    .pipe(uglify())
    .pipe(gulp.dest('./leadership/angular/js'));
});

gulp.task('video-widget-extras:fastclick:js', [], () => {
  return gulp.src(['./video_widget/video_widget_includes/js/fastclick.js'], {base: '.'})
    .pipe(rename({ suffix: '.min' }))
    .pipe(uglify())
    .pipe(gulp.dest('.'));
});

gulp.task('video-widget-extras:js', ['video-widget-extras:fastclick:js'], () => {
  return gulp.src(['./video_widget/video_widget_includes/src/**/*.js'])
    .pipe(sourcemaps.init())
    .pipe(babel({ presets: ['es2015'] }))
    .pipe(replace(/["']use strict["'];/, ''))
    .pipe(gulp.dest('./video_widget/video_widget_includes/js'))
    .pipe(rename({ suffix: '.min' }))
    .pipe(uglify())
    .pipe(gulp.dest('./video_widget/video_widget_includes/js'))
});

gulp.task('purf:js:watch', () => {
  gulp.watch(['./smg_pop_up/js/purf-object.js', './smg_pop_up/js/purf.js', './smg_pop_up/js/ctools-override.js'], ['purf:js']);
});

gulp.task('purf:js:all', ['purf:js', 'purf:js:watch']);

