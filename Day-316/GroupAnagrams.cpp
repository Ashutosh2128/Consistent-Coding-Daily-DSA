/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    const map = new Map();

    for(const str of strs) {
        const sortStr = str.split('').sort().join('');
        if(!map.has(sortStr)) map.set(sortStr, []);
        map.get(sortStr).push(str);
    }

    const ans = [];
    for([key, value] of map) ans.push(value);

    return ans;
};