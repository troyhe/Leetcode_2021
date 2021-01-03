class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int maxSum = nums[0];
        int sum = nums[0];
        for (int i = 1; i < nums.size(); i++){
            sum = nums[i] + max(sum, 0);
            maxSum = max(maxSum, sum);
        }
        return maxSum;
    }
};
