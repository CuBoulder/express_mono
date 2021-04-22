const { watch, src, dest } = require('gulp');
const sass = require('gulp-dart-sass');
const log = require('fancy-log');

const glob = ['**/*.scss', '!node_modules/**/*.scss', '!**/_*.scss'];

// Tasks
function watchScss() {
  const watcher = watch(glob, {cwd: '.'})
    .on('change', compileSingleScss);
}

function compileSingleScss(path) {
  return src(path)
    .pipe(sass())
    .pipe(dest(getDestPath));
}

function compileAllScss() {
  return src(glob)
    .pipe(sass())
    .pipe(dest(getDestPath));
}

// Helpers
function getDestPath(file) {
  let scssFilename = 'A .scss file';
  const scssPathParts = file.path.split('/');

  const cssPathParts = scssPathParts.map(part => {
    if (part === "scss") {
      part = 'css';
    }

    if (part.includes('.')) {
      scssFilename = part;
      part = '';
    }

    return part;
  });

  const cssPath = cssPathParts.join('/');
  log(`Compiled ${scssFilename} to CSS and writing it to ${cssPath}`);
  return cssPath;
}

exports.default = watchScss;
exports.compileAllScss = compileAllScss;
