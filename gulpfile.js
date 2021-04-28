const { watch, src, dest } = require('gulp');
const sass = require('gulp-dart-sass');
const log = require('fancy-log');

const glob = ['**/*.scss', '!node_modules/**/*.scss', '!**/_*.scss'];
let fileCount = 0;

// Tasks
function watchScss() {
  const watcher = watch(glob, {cwd: '.'})
    .on('change', compileSingleScss);
}

function compileSingleScss(path) {
  console.log("path from watch:", path);
  return src(path)
    .pipe(sass())
    .pipe(dest(getDestPath));
}

function compileAllScss() {
  return src(glob)
    .pipe(sass())
    .pipe(dest(getDestPath));
}

// Function to rewrite the path of the compiled and saved vinylFile.
function getDestPath(vinylFile) {
  fileCount += 1;

  let filename = `style-${fileCount}`;
  const scssPathParts = vinylFile.path.split('/');

  const cssPathParts = scssPathParts.map(part => {
    if (part === "scss") {
      part = 'css';
    }

    if (part.includes('.')) {
      filename = part;
      part = '';
    }

    return part;
  });

  const destPath = cssPathParts.join('/');
  vinylFile.path = `${destPath}/${filename}`;
  vinylFile.dirname = destPath;
  return vinylFile.cwd;
}

exports.default = watchScss;
exports.compileAllScss = compileAllScss;
