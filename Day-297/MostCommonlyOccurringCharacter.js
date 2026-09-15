const mostCommonCharacter = str => {
  const arr = Array.from({length: 26}, () => 0);
  [...str].forEach(e => arr[e.toLowerCase().charCodeAt(0) - 'a'.charCodeAt(0)]++);
  // console.log(arr);
  return String.fromCharCode('a'.charCodeAt(0) + arr.reduce((max, curr, idx) => arr[max] >= curr ? max : idx, -1));
};