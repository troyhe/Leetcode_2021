class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans(2, -1);
        if (nums.size() == 0) return ans;
        int left = 0;
        int right = nums.size();
        // find the smallest n that nums[n] = target
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] < target){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        if (left == nums.size() || nums[left] != target) return ans;
        ans[0] = left;
        // left = 0;
        right = nums.size();
        // find the larget n that nums[n] = target
        while (left < right){
            int mid = left + (right - left)/2;
            if (nums[mid] <= target){
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        ans[1] = left - 1;
        return ans;
    }
};
