const arr1 = [1, 2, 3];
const arr2 = [[1, 2], [3, 4], [5, 6]];
const arr3 = [[[1, 2], [3, 4]], [[5, 6], [7, 8]]];
const arr4 = [[1, 2], [[3, 4], [[5, 6]]], 7];
const notArr = 5;

const levelCount = arr => {
  if(!Array.isArray(arr)) return 0;
  
  let maxCnt = 0;
  let cnt = 1;
  arr.forEach(val => {
    ans = levelCount(val);
    cnt += ans;
    maxCnt = maxCnt > cnt ? maxCnt : cnt;
    cnt -= ans; //backtrack
  })
  
  return maxCnt;
}

const nestedArrayCheck = arr => {
  const level = levelCount(arr);
  
  if(level === 0) return "Input is not an array";
  else if(level === 1) return "Input is an array";
  else return `Input is a nested array with ${level} levels`
}

console.log(nestedArrayCheck(arr1));
console.log(nestedArrayCheck(arr2));
console.log(nestedArrayCheck(arr3));
console.log(nestedArrayCheck(arr4));
console.log(nestedArrayCheck(notArr));