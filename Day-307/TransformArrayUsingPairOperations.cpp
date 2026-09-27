class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long sum1 = accumulate(source.begin(), source.end(), 0LL);
        long long sum2 = accumulate(target.begin(), target.end(), 0LL);

        return sum1 == sum2;
    }
};