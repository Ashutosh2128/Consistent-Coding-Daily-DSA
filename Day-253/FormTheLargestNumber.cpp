class Solution {
  public:
    static bool cmp(string a, string b) {
        if((a+b) > (b+a)) return true;
        else return false;
    }
  
    string findLargest(vector<int> &arr) {
        vector<string> strArr(arr.size());
        for(int i = 0; i < arr.size(); i++) {
            strArr[i] = to_string(arr[i]);
        }
        
        sort(strArr.begin(), strArr.end(), cmp);
        if(strArr[0] == "0") return "0";
        
        string ans = "";
        
        for(auto it : strArr) ans += it;
        return ans;
    }
};