module.exports = function (grunt) {
    grunt.initConfig({
        requirejs: {
            compile: {
                options: {

                }
            }
        },
        babel: {
            purf: {
                files: [
                    {
                        expand: true,
                        cwd: 'smg_pop_up/js/',
                        src: ['purf-object.js', 'purf.js', 'ctools-override.js'],
                        dest: 'smg_pop_up/js/build/',
                        ext: '.js'
                    }
                ]
            }
        },
        concat: {
            purf: {
                src: ['smg_pop_up/js/build/purf-object.js', 'smg_pop_up/js/build/purf.js', 'smg_pop_up/js/build/ctools-override.js'],
                dest: 'smg_pop_up/js/smg-pop-up.js'
            }
        },
        uglify: {
            extra_video_widget: {
                files: [{
                    expand: true,
                    cwd: 'video_widget/video_widget_includes/js',
                    src: ['**/*.js', '!**/*.min.js'],
                    dest: 'video_widget/video_widget_includes/js',
                    ext: '.min.js',
                    extDot: 'first'
                }]
            },
            video_widget: {
                options: {
                    beautify: true,
                    mangle: true
                },
                files: {
                    'video_widget/video_widget_includes/angular/app.min.js': 'video_widget/video_widget_includes/angular/app.js',
                    'video_widget/video_widget_includes/angular/videoGrid.min.js': 'video_widget/video_widget_includes/angular/videoGrid.js'
                }
            },
            purf: {
                files: {
                    'smg_pop_up/js/smg-pop-up.min.js': ['smg_pop_up/js/build/purf-object.js', 'smg_pop_up/js/build/purf.js', 'smg_pop_up/js/build/ctools-override.js']
                }
            }
        },
        eslint: {
            purf: {
                files: {
                    src: ['smg_pop_up/js/smg-pop-up.js']
                }
            }
        },
        jslint: {
            purf: {
                src: ['smg_pop_up/js/smg-pop-up.js']
            }
        },
        clean: {
            purf: ["smg_pop_up/js/build"]
        }
    });

    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.loadNpmTasks('grunt-contrib-concat');
    grunt.loadNpmTasks('grunt-contrib-clean');
    grunt.loadNpmTasks('eslint-grunt');
    grunt.loadNpmTasks('grunt-jslint');
    grunt.loadNpmTasks('grunt-babel');

    grunt.registerTask('default', ['uglify', 'uglify:video_widget', 'uglify:extra_video_widget', 'uglify:leadership_angular', 'concat:purf', 'uglify:purf']);
    grunt.registerTask('purf', ['babel:purf', 'concat:purf', 'uglify:purf', 'clean:purf']);
}