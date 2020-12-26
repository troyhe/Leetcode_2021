class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (m < n) return findMedianSortedArrays(nums2, nums1);
        int left = 0;
        int right = n;
        int x1;
        int x2;
        int x1_left, x1_right, x2_left, x2_right;
        while (left <= right){
            x1 = (left + right)/2;
            x2 = (m+n)/2 - x1;
            x1_left = (x1 == 0)?INT_MIN: nums1[x1-1];
            x1_right = (x1 == n)?INT_MAX: nums1[x1];
            x2_left = (x2 == 0)?INT_MIN: nums2[x2-1];
            x2_right = (x2 == m)?INT_MAX: nums2[x2];
            if (x1_left > x2_right){
                right = x1 - 1;
            } else if (x1_right < x2_left){
                left = x1 + 1;
            } else {
                break;
            }
        }
        if ((m + n) % 2 == 1) return min(x1_right, x2_right);
        double small = max(x1_left, x2_left);
        double large = min(x1_right, x2_right);
        return (small + large)/2;
    }
};
