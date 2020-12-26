class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int farthest = nums[0];
        for (int i = 1; i <= farthest && i < nums.size(); i++){
            farthest = max(farthest, nums[i]+i);
            if (farthest >= nums.size() - 1) return true;
        }
        return false;
    }
};
