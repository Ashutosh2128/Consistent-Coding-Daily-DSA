const mergeIntervals = intervals => {
  return intervals.reduce((merged, curr) => {
    if(merged.length === 0 || merged[merged.length-1][1] < curr[0]) merged.push(curr);
    else merged[merged.length-1][1] = curr[1];
    
    return merged;
  }, [])
}