/******************************************************************************
 * Gulpfile
 * Be sure to run `npm install` for `gulp` and the following tasks to be
 * available from the command line. All tasks are run using `gulp taskName`.
 ******************************************************************************/
var gulp = require('gulp'),
    webpack = require('webpack'),
    watch = require('gulp-watch'),
    del = require('del');


/******************************************************************************
 * watch
 * Build the app and watch for source file changes.
 ******************************************************************************/
gulp.task('watch', ['copy.html', 'copy.css'], function (done) {
    watch('app/**/*.html', function () {
        gulp.start('copy.html');
    });

    watch('app/**/*.css', function () {
        gulp.start('copy.css');
    })

    // watch('app/**/*.ts', function() {
    //     bundle(false, done);
    // });
    bundle(true, done);
});


/******************************************************************************
 * build
 * Build the app once, without watching for source file changes.
 ******************************************************************************/
gulp.task('build', ['copy.html'], function (done) {
    bundle(false, done);
});



gulp.task('copy.css', function (done) {
    return gulp.src('app/**/*.css')
        .pipe(gulp.dest('www/build'));
});


/******************************************************************************
 * copy.html
 * Copy html files to build directory.
 ******************************************************************************/
gulp.task('copy.html', function () {
    return gulp.src('app/**/*.html')
        .pipe(gulp.dest('www/build'));
});


/******************************************************************************
 * clean
 * Delete previous build files.
 ******************************************************************************/
gulp.task('clean', function (done) {
    del(['www/build'], done);
});


/******************************************************************************
 * Bundle
 * Transpiles source files and bundles them into build directory using webpack.
 ******************************************************************************/
function bundle(watch, cb) {
    // prevent gulp calling done callback more than once when watching
    var firstTime = true;

    // load webpack config
    var config = require('./webpack.config.js');

    // https://github.com/webpack/docs/wiki/node.js-api#statstojsonoptions
    var statsOptions = {
        'colors': true,
        'modules': false,
        'chunks': false,
        'exclude': ['node_modules']
    }

    var compiler = webpack(config);
    if (watch) {
        compiler.watch(null, compileHandler);
    } else {
        compiler.run(compileHandler);
    }

    function compileHandler(err, stats) {
        if (firstTime) {
            firstTime = false;
            cb();
        }

        // print build stats and errors
        console.log(stats.toString(statsOptions));
    }
}
