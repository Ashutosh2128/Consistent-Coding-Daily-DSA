var groupAnagrams = function(strs) {
    const map = new Map();

    for(const str of strs) {
        const sorted = str.split("").sort().join("");
        if(!map.has(sorted)) map.set(sorted, []);
        map.get(sorted).push(str);
    }

    const ans = [];
    for(const [key, value] of map) ans.push(value);

    return ans;
};