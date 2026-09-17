const simplifyPath = path => {
  // console.log(path.split('/'));
  return '/' + path.split('/').reduce((finalPath, curr) => {
    if(curr === '..') finalPath.pop();
    else if(curr !== '.' && curr !== '') finalPath.push(curr);
    return finalPath;
  }, []).join('/')
}