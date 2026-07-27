class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = INT_MIN;
        int secondMax = INT_MIN;

        for(const int& it : nums) {
            if(it > firstMax) {
                secondMax = firstMax;
                firstMax = it;
            }
            else if(it > secondMax) secondMax = it;
        }

        return (firstMax-1) * (secondMax-1);
    }
};





// O(N) and O(1) require
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         priority_queue<int, vector<int>, greater<int>> minHeap;

//         for(const int& it : nums) {
//             minHeap.push(it);
//             if(minHeap.size() > 2) minHeap.pop();
//         }

//         int first = minHeap.top();
//         minHeap.pop();
//         int second = minHeap.top();
//         minHeap.pop();

//         return (first-1) * (second-1);
//     }
// };






// O(N logN) and O(1) requires
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return (nums[nums.size()-1]-1) * (nums[nums.size()-2]-1);
//     }
// };