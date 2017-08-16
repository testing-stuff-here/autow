var gulp = require('gulp');
var jshint = require('gulp-jshint');
var concat = require('gulp-concat');
var rename = require('gulp-rename');
var uglify = require('gulp-uglify');
var watch = require('gulp-watch');
var sass = require('gulp-sass');
var haml = require('gulp-ruby-haml');
var order = require('gulp-order');
var livereload = require('gulp-livereload');
var plumber = require('gulp-plumber');
var autoprefixer = require('gulp-autoprefixer');
var stripDebug = require('gulp-strip-debug');
var sourcemaps = require('gulp-sourcemaps');
var filesize = require('gulp-filesize');
var imageop = require('gulp-image-optimization');
var notify = require('gulp-notify');
var shell = require('gulp-shell');

// Lint Task
gulp.task('jshint', function() {
 return gulp.src(['js/main.js', 'js/article-flow.js', 'js/menu-sugar.js',
   'js/subscribe/pswidget-jq.js', 'js/subscribe/pswidget-ractive.js'
  ])
  .pipe(plumber())
  .pipe(jshint())
  .pipe(jshint.reporter('jshint-stylish'))
  .pipe(notify({
   message: 'JSHint task complete.'
  }))
  .pipe(livereload());
});

// Compile Our Sass
gulp.task('sass', function() {
 return gulp.src('scss/*.scss')
  .pipe(plumber())
  .pipe(sourcemaps.init())
  .pipe(sass({
   includePaths: ['./bootstrap/assets/stylesheets', 'animate', './lib', '/bootstrap/assets/stylesheets'],
   sourcemap: true,
   sourceComments: 'map',
   outputStyle: 'compressed',
   errLogToConsole: true
  }))
  .pipe(autoprefixer())
  .pipe(sourcemaps.write())
  .pipe(rename('style.css'))
  .pipe(gulp.dest('./dist/css'))
  .pipe(notify({
   message: 'Scss task complete.'
  }))
  .pipe(filesize())
  .pipe(livereload());
});

// Concatenate & Minify JS
gulp.task('scripts', function() {
 return gulp.src([
   'js/subscribe/libs/jquery-ui.js',
   'js/subscribe/libs/autocomplete.ui.js',
   'js/subscribe/libs/polyfiller.js',
   'js/subscribe/libs/watch.js',
   'js/modernizr.js',
   'js/lodash.min.js',
   'js/vissense.js',
   'js/owl.carousel.js',
   'js/main.js',
   'js/article-flow.js',
   'js/menu-sugar.js'
  ])
  .pipe(plumber())
  .pipe(stripDebug())
  .pipe(concat('awbs.js'))
  .pipe(gulp.dest('dist/js'))
  .pipe(stripDebug())
  .pipe(uglify('awbs.js'))
  .pipe(rename('awbs.min.js'))
  .pipe(gulp.dest('dist/js'))
  .pipe(sourcemaps.write())
  .pipe(notify({
   message: 'Scripts task complete.'
  }))
  .pipe(filesize())
  .pipe(livereload());
});

gulp.task('subscripts', function() {
 return gulp.src([
   'js/subscribe/libs/ractive.js',
   'js/subscribe/pswidget-jq.js',
   'js/subscribe/libs/ractive/ractive-keys.js',
   'js/subscribe/libs/ractive/ractive-events-typing.js',
   'js/subscribe/libs/ractive/ractive-transitions-fade.js',
   'js/subscribe/libs/ractive/ractive-transitions-slide.js',
   'js/subscribe/libs/ractive/ractive-transitions-fly.js',
   'js/subscribe/libs/ractive/ractive-transitions-scale.js',
   'js/subscribe/libs/ractive/Ractive-adaptors-Promise.js',
   'js/subscribe/pswidget-ractive.js',
  ])
  .pipe(plumber())
  .pipe(concat('awbs.subscriptions.js'))
  .pipe(gulp.dest('dist/js'))
  .pipe(stripDebug())
  .pipe(uglify('awbs.subscriptions.js'))
  .pipe(rename('awbs.subscriptions.min.js'))
  .pipe(gulp.dest('dist/js'))
  .pipe(sourcemaps.write())
  .pipe(notify({
   message: 'Subscrition script task complete.'
  }))
  .pipe(filesize())
  .pipe(livereload());
});


gulp.task('images', function(cb) {
 gulp.src('preimages/**/*.+(png|jpg|gif|jpeg)').pipe(imageop({
  optimizationLevel: 5,
  progressive: true,
  interlaced: true
 })).pipe(gulp.dest('images'));
});

gulp.task('images-sys', function(cb) {
 gulp.src([
  '/Applications/MAMP/htdocs/aw2/sites/default/files/styles/stage_one_form/heroshot_1.png',
  '/Applications/MAMP/htdocs/aw2/sites/default/files/styles/stage_one_form/awsurvivalguide_heror2_0.png'
 ]).pipe(imageop({
  optimizationLevel: 5,
  progressive: true,
  interlaced: true
 })).pipe(gulp.dest(
  '/Applications/MAMP/htdocs/aw2/sites/default/files/styles/stage_one_form/public'
 ));
});

gulp.task('cc-css-js', shell.task[
  'echo drush cc css-js'
]);

// Watch Files For Changes
gulp.task('watch', function() {
 gulp.watch('js/**/*.js', ['jshint', 'scripts', 'cc-css-js']);
 gulp.watch('scss/*.scss', ['sass', 'cc-css-js']);
 // gulp.watch('pswidget.html', ['copy']);
 livereload.listen();
});

// Default Task
gulp.task('default', ['jshint', 'sass', 'scripts', 'subscripts', 'watch', 'cc-css-js']);
gulp.task('imageopt', ['images-sys']);
