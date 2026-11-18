class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        if(n2 == 0) return n1 & 1 ? nums1[n1/2] : (nums1[n1/2] + nums1[n1/2-1]) / 2.0;
        if(n1 == 0) return n2 & 1 ? nums2[n2/2] : (nums2[n2/2] + nums2[n2/2-1]) / 2.0;

        vector<int> merge(n);
        int i = 0, j = 0, idx = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) merge[idx++] = nums1[i++];
            else merge[idx++] = nums2[j++];
        }

        while(i < n1) merge[idx++] = nums1[i++];
        while(j < n2) merge[idx++] = nums2[j++];

        return n & 1 ? merge[n/2] : (merge[n/2] + merge[n/2-1]) / 2.0;
    }
};