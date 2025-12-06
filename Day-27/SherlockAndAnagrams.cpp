int sherlockAndAnagrams(string s) {
    unordered_map<string, int> mp;
    string subString;
    
    for(int i = 0; i < s.length(); i++) {
        subString.clear();
        
        for(int j = i; j < s.length(); j++) {
            subString.push_back(s[j]);
        
            sort(subString.begin(), subString.end());
            mp[subString]++;
        }
    }
    
    int anagramCount = 0;
    for(auto each : mp) {
        int count = each.second;
        if(count > 1) anagramCount += (count * (count - 1)) / 2;
    }
    
    return anagramCount;
}