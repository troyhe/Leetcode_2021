class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        if (nums.size() < k) return 0;
        int sum = 0;
        for (int i = 0; i < k; i++) sum += nums[i];
        int maxSum = sum;
        for (int i = 0; i < nums.size() - k; i++){
            sum -= nums[i];
            sum += nums[i+k];
            maxSum = max(maxSum, sum);
        }
        return maxSum*1.0 / k;
    }
};
