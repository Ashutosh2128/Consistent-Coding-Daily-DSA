class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int& it : nums) freq[it]++;

        vector<int> distinct;
        for(auto& p : freq) distinct.push_back(p.first);
        sort(distinct.begin(), distinct.end());

        // Now in distinct array I got all the distinct element so go through it and push one by one in ans vector till it's freq goes 0
        vector<int> ans;
        while(1) {
            bool added = false;

            for(auto& it : distinct) {
                if(freq[it]) {
                    ans.push_back(it);
                    freq[it]--;
                    added = true;
                }
            }

            if(!added) break;
        }

        return ans;
    }
};






// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         vector<int> freq(101, 0);
//         for(int i = 0; i < nums.size(); i++) freq[nums[i]]++;

//         vector<int> ans;
//         for(int round = 0; round < 100; round++) {
//             for(int i = 1; i < 101; i++) {
//                 if(freq[i] > 0) {
//                     ans.push_back(i);
//                     freq[i]--;
//                 }
//             }
//         }

//         return ans;
//     }
// };