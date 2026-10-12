class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)(k1 + k2);

        unordered_map<int, int> freq;
        long long acc = 0;
        for(int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            acc += diff;
            freq[diff]++;
        }

        if(acc <= k) return 0;

        priority_queue<pair<int, int>> maxHeap;
        for(auto& [first, second] : freq) maxHeap.push({first, second});

        while(k) {
            auto [largest, count] = maxHeap.top();
            maxHeap.pop();

            if(!maxHeap.empty() && largest == maxHeap.top().first) {
                count += maxHeap.top().second;
                maxHeap.pop();
            }

            int next = maxHeap.empty() ? 0 : maxHeap.top().first;
            long long cost = 1LL * (largest - next) * count;

            if(cost <= k) {
                maxHeap.push({next, count});
                k -= cost;
            }
            else {
                long long dec = k / count;
                long long rem = k % count;

                if(dec) maxHeap.push({largest - dec, count-rem});
                else maxHeap.push({largest, count-rem});

                if(rem) maxHeap.push({largest - dec - 1, rem});
                
                break;
            }
        }

        long long sum = 0;
        while(!maxHeap.empty()) {
            auto [largest, count] = maxHeap.top();
            maxHeap.pop();

            sum += 1LL * largest * largest * count;
        }

        return sum;
    }
};










// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         int n = nums1.size();
//         long long k = (long long)(k1 + k2);

//         unordered_map<int, int> freq;
//         long long acc = 0;
//         for(int i = 0; i < n; i++) {
//             int d = abs(nums1[i] - nums2[i]);
//             freq[d]++;
//             acc += d;
//         }

//         if(acc <= k) return 0;

//         priority_queue<pair<int, int>> maxHeap;
//         for(auto& [d, count] : freq) {
//             maxHeap.push({d, count});
//         }

//         while(k) {
//             auto[largest, count] = maxHeap.top();
//             maxHeap.pop();

//             if(largest == 0) break;

//             if(!maxHeap.empty() && largest == maxHeap.top().first) {
//                 count += maxHeap.top().second;
//                 maxHeap.pop();
//             }

//             int next = maxHeap.empty() ? 0 : maxHeap.top().first;
//             long long cost = 1LL * (largest - next) * count;

//             if(k >= cost) {
//                 k -= cost;
//                 maxHeap.push({next, count});
//             }
//             else {
//                 long long dec = k / count;
//                 long long rem = k % count;

//                 if(dec > 0) maxHeap.push({largest - (int)dec, count - (int)rem});
//                 else maxHeap.push({largest, count - (int)rem});

//                 if(rem > 0) maxHeap.push({largest - (int)dec - 1, (int)rem});

//                 k = 0;
//             }
//         }

//         long long sum = 0;
//         while(!maxHeap.empty()) {
//             auto [d, count] = maxHeap.top();
//             maxHeap.pop();
//             sum += 1LL * d * d * count;
//         }

//         return sum;
//     }
// };










// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         int n = nums1.size();
//         long long k = (long long)k1 + k2;

//         vector<int> diff(n);
//         long long acc = 0;
//         for(int i = 0; i < n; i++) {
//             diff[i] = abs(nums1[i] - nums2[i]);
//             acc += diff[i];
//         }

//         if(acc <= k) return 0;

//         // storing frequency of element
//         unordered_map<int, int> freq;
//         for(int& it : diff) freq[it]++;

//         priority_queue<pair<int, int>> maxHeap;
//         for(auto& [first, second] : freq) maxHeap.push({first, second});

//         while(k) {
//            auto[largest, count] = maxHeap.top();
//             maxHeap.pop();

//             if(largest == 0) break;

//             // Let say k is less than freqency count then reduce 1 only for k element, other top.second-k element store separately in maxHeap then simply break
//             if(k < count) {
//                 maxHeap.push({largest-1, k});
//                 maxHeap.push({largest, count-k});
//                 break;
//             }

//             // Now try to decrease the whole group by k times till second top element if k >= (top.first - maxHeap.top().first) * 
            
//             largest -= 1;
//             maxHeap.push({largest, count});
//             k -= count;
//         }

//         long long sum = 0;
//         while(!maxHeap.empty()) {
//             long long topFirst = maxHeap.top().first;
//             sum += topFirst * topFirst * maxHeap.top().second;
//             maxHeap.pop();
//         }

//         return sum;
//     }
// };






// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
//         int n = nums1.size();
//         int k = k1 + k2;

//         vector<int> diff(n);
//         for(int i = 0; i < n; i++) diff[i] = abs(nums1[i] - nums2[i]);

//         while(k--) {
//             sort(diff.begin(), diff.end());
//             if(diff[n-1] == 0) break;
//             diff[n-1] -= 1;
//         }

//         long long sum = 0;
//         for(int& it : diff) sum += 1LL * it * it;

//         return sum;
//     }
// };