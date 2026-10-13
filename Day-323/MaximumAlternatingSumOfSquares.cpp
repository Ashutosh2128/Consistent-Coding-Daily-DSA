class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> square;
        for(int& num : nums) square.push_back(1LL * num * num);

        sort(square.begin(), square.end());
        long long sum = accumulate(square.begin(), square.end(), 0LL);
        long long halfSum = accumulate(square.begin(), square.begin()+square.size()/2, 0LL);

        return sum - 2 * halfSum;
    }
};