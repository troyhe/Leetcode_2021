class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int step = 1;
        int farthest = nums[0];
        int lastFarthest = 0;;
        while (farthest < nums.size() - 1){
            step++;
            int maxStep = 0;
            for (int i = lastFarthest + 1; i <= farthest; i++){
                maxStep = max(maxStep, nums[i] + i);
            }
            lastFarthest = farthest;
            farthest = maxStep;
        }
        return step;

    }
};
