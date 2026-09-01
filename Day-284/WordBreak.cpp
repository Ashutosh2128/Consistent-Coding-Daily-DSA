class Solution {
public:
    bool checkValid(string& word, vector<string>& wordDict) {
        for(string it : wordDict) if(it == word) return true;
        return false;
    }

    bool solveUsingBU(string& s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1, 1);

        for(int start = s.size()-1; start >= 0; start--) {
            string word = "";
            bool flag = false;
            for(int i = start; i < s.size(); i++) {
                word += s[i];
                if(checkValid(word, wordDict)) flag = flag || dp[i+1];
            }

            dp[start] = flag;
        }

        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        return solveUsingBU(s, wordDict);
    }
};








// class Solution {
// public:
//     bool checkValid(string& word, vector<string>& wordDict) {
//         for(string it : wordDict) if(it == word) return true;
//         return false;
//     }

//     bool solveUsingTD(string& s, vector<string>& wordDict, int start, vector<int>& dp) {
//         if(start >= s.size()) return true;

//         if(dp[start] != -1) return dp[start];

//         string word = "";
//         bool flag = false;
//         for(int i = start; i < s.size(); i++) {
//             word += s[i];
//             if(checkValid(word, wordDict)) flag = flag || solveUsingTD(s, wordDict, i+1, dp);
//         }

//         dp[start] = flag;
//         return dp[start];
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         vector<int> dp(s.size()+1, -1);
//         return solveUsingTD(s, wordDict, 0, dp);
//     }
// };









// class Solution {
// public:
//     bool checkValid(string& word, vector<string>& wordDict) {
//         for(string it : wordDict) if(it == word) return true;
//         return false;
//     }

//     bool solveUsingRec(string& s, vector<string>& wordDict, int start) {
//         if(start >= s.size()) return true;

//         string word = "";
//         bool flag = false;
//         for(int i = start; i < s.size(); i++) {
//             word += s[i];
//             if(checkValid(word, wordDict)) flag = flag || solveUsingRec(s, wordDict, i+1);
//         }

//         return flag;
//     }

//     bool wordBreak(string s, vector<string>& wordDict) {
//         return solveUsingRec(s, wordDict, 0);
//     }
// };