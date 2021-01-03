class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = m + n - 1;
        m--;
        n--;
        while (m >= 0 && n >= 0){
            nums1[cur--] = (nums1[m] > nums2[n])?nums1[m--]:nums2[n--];
        }
        if (n >= 0){
            for (int i = 0; i <= n; i++){
                nums1[i] = nums2[i];
            }
        }
    }
};
