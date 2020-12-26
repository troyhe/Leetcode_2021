class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() <= 2) return INT_MAX;
        sort(nums.begin(), nums.end());
        int minDistance = INT_MAX;
        int minSum = 0;
        for (int i = 0; i < nums.size() - 2; i++){
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < minDistance){
                    minSum = sum;
                    minDistance = abs(sum - target);
                }
                if (sum == target){
                    minSum = sum;
                    break;
                } else if (sum < target){
                    left ++;
                } else {
                    right --;
                }
                
            }
        }
        
        return minSum;
    }
};
