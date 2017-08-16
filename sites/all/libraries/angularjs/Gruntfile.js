module.exports = function (grunt) {
  grunt.initConfig({
    concat: {
      dist: {
        src: ['bower_components/angular/angular.min.js','bower_components/angular-sanitize/angular-sanitize.min.js', 'bower_components/angular-touch/angular-touch.min.js'],
        dest: 'prod/angular_compressed_min.js',
      },
    },
  });

  grunt.loadNpmTasks('grunt-contrib-concat');
  
  grunt.registerTask('default', ['concat']);
}
