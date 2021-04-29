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
  console.log('PATH from compileSingleScss', path);
  return src(path)
    .pipe(sass())
    .pipe(dest((vinylFile) => getDestPath(true, vinylFile)));
}

function compileAllScss() {
  return src(glob)
    .pipe(sass())
    .pipe(dest((vinylFile) => getDestPath(false, vinylFile)));
}

// Function to rewrite the path of the compiled and saved vinylFile.
function getDestPath(isSingleScssFile, vinylFile) {
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

  let destPath = '';

  if (isSingleScssFile) {
    destPath = cssPathParts.join('/');
  }
  else {
    vinylFile.path = `${destPath}/${filename}`;
    vinylFile.dirname = cssPathParts.join('/');
    console.log(`vinylFile.path:`, vinylFile.path);
    console.log(`vinylFile.dirname:`, vinylFile.dirname);
    console.log(`vinylFile.cwd:`, vinylFile.cwd);
    destPath = vinylFile.cwd;
  }

  log(`Writing ${vinylFile.path}...`);
  return destPath;
}

exports.default = watchScss;
exports.compileAllScss = compileAllScss;
