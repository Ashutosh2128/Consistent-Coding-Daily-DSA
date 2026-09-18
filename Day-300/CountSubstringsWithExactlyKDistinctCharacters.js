const countSubstrings = (string, k) => {
  const anagram = new Set();
  const subString = [];
  
  for(let i = 0; i < string.length; i++) {
    for(let j = i+1; j <= string.length; j++) {
      const subStr = string.slice(i, j);
      const checkLength = new Set(subStr).size;
      
      if(checkLength === k) {
        const sortStr = subStr.split('').sort().join('');
        if(!anagram.has(sortStr)) {
          subString.push(subStr);
          anagram.add(sortStr);
        }
      }
    }
  }
  
  console.log(`Distinct substrings with exactly ${k} distinct characters:`, subString)
  return subString.length;
}