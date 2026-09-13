const splitArray = ({ arr, maxlen }) => {
  // return Array.from({ length: Math.ceil(arr.length / maxlen) })
  // .map((_, idx) => arr.slice(idx * maxlen, (idx+1) * maxlen));
  
  // return Array.from({ length: Math.ceil(arr.length / maxlen) }, (_, idx) => idx).map(num => arr.slice(num * maxlen, (num+1) * maxlen)) 
  
  return Array.from({ length: Math.ceil(arr.length / maxlen) }, (_, idx) => idx + 1).map((num, idx) => arr.slice(idx * maxlen, num * maxlen));
};