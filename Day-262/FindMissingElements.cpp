class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<bool> freq(101, false); // as per constraints
        for(const int& it : nums) freq[it] = true;

        // finding min element
        int min = -1;
        for(int i = 0; i < 101; i++) {
            if(freq[i]) {
                min = i;
                break;
            }
        }

        int max = -1;
        for(int i = 100; i >= 0; i--) {
            if(freq[i]) {
                max = i;
                break;
            }
        }

        vector<int> ans;
        for(int i = min+1; i < max; i++) if(!freq[i]) ans.push_back(i);

        return ans;
    }
};




// class Solution {
// public:
//     vector<int> findMissingElements(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         vector<int> ans;
//         for(int i = 0; i < nums.size()-1; i++) {
//             int diff = nums[i+1] - nums[i] - 1;
//             if(diff > 0) {
//                 int store = nums[i] + 1;
//                 for(int j = 0; j < diff; j++) ans.push_back(store++);
//             }
//         }

//         return ans;
//     }
// };