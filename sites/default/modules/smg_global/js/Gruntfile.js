module.exports = function (grunt) {
  grunt.initConfig({
    concat: {
      purf: {
        src: ['smg_pop_up/js/purf-object.js', 'smg_pop_up/js/purf.js'],
        dest: 'smg_pop_up/js/smg-pop-up.js'
      }
    },
    uglify: {      
      smgGlobal: {
        files: {
          'smg_global.min.js': ['smg_global.js']
        }
      }
    },    
    jslint: {    
    }
  });

  grunt.loadNpmTasks('grunt-contrib-uglify');
  grunt.loadNpmTasks('grunt-contrib-concat');
  grunt.loadNpmTasks('eslint-grunt');  
  
  grunt.registerTask('smgGlobal', ['uglify:smgGlobal']);
}