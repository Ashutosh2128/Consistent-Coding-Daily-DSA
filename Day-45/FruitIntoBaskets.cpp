class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int i = 0;
        int maxLen = 0;

        for(int j = 0; j < fruits.size(); j++) {
            mp[fruits[j]]++;

            if(mp.size() > 2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) mp.erase(fruits[i]);
                i++;
            }
            else 
                maxLen = max(maxLen, (j - i + 1));
        }

        return maxLen;
    }
};



// Code perfect but TLE
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         int maxLen = 0;

//         for(int i = 0; i < fruits.size(); i++) {
//             set<int> st;

//             for(int j = i; j < fruits.size(); j++) {
//                 st.insert(fruits[j]);

//                 if(st.size() <= 2) maxLen = max(maxLen, (j - i + 1));
//                 else break;
//             }
//         }

//         return maxLen;
//     }
// };




// Only passed 32 test cases
// class Solution {
// public:
//     int totalFruit(vector<int>& fruits) {
//         sort(fruits.begin(), fruits.end());
//         map<int, int> mp;

//         for(int i : fruits) {
//             mp[i]++;
//         }

//         int count = 0;

//         int max = 1;
//         int maxPrev = 1;

//         for(auto it : mp) {
//             if(it.second >= max) {
//                 maxPrev = max;
//                 max = it.second;
//             }
//         }

//         return maxPrev + max;
//     }
// };