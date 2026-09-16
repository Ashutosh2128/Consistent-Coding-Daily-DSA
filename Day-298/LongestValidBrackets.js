const longestValidBrackets = str => {
  const st = [-1];
  return str.split('').reduce((max, ch, i) => {
    if(ch === '[') st.push(i);
    else {
      st.pop();
      if(st.length === 0) st.push(i);
      else max = Math.max(max, i - st[st.length-1]);
    }
    
    return max;
  }, 0)
}