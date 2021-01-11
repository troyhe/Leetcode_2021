class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> leftMax(nums.size(), 0);
        vector<int> rightMax(nums.size(), 0);
        vector<int> ans(nums.size() - k + 1, 0);
        int curMax = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            curMax = max(curMax, nums[i]);
            leftMax[i] = curMax;
            if (i % k == k - 1) curMax = INT_MIN;
        }
        curMax = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--){
            curMax = max(curMax, nums[i]);
            rightMax[i] = curMax;
            if (i % k == 0) curMax = INT_MIN;
        }
        for (int i = 0; i < nums.size() - k + 1; i++){
            ans[i] = max(leftMax[i+k-1], rightMax[i]);
        }
        return ans;
    }
};
