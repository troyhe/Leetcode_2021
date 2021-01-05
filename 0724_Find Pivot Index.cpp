class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftSum = 0;
        int rightSum = 0;
        if (nums.empty()) return -1;
        for (int i = 1; i < nums.size(); i++) rightSum += nums[i];
        for (int i = 0; i < nums.size() - 1; i++){
            if (leftSum == rightSum) return i;
            leftSum += nums[i];
            rightSum -= nums[i+1];
        }
        if (leftSum == rightSum) return nums.size() - 1;
        else return -1;
        
    }
};
