class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int maxPro = nums[0];
        int maxPositive = nums[0];
        int minNegative = nums[0];
        int temp;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] == 0){
                maxPositive = minNegative = 0;
            } else if (nums[i] > 0){
                //temp = minNegative;
                maxPositive = max(nums[i], maxPositive * nums[i]);
                minNegative = min(nums[i], minNegative * nums[i]);
            } else {
                temp = minNegative;
                minNegative = min(nums[i], maxPositive * nums[i]);
                maxPositive = max(nums[i], temp * nums[i]);
            }
            maxPro = max(maxPro, maxPositive);
        }
        return maxPro;
    }
};
