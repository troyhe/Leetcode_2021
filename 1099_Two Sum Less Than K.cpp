class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxNum = -1;
        int left = 0;
        int right = nums.size() - 1;
        while (left < right){
            int sum = nums[left] + nums[right];
            if (sum >= k) right--;
            else {
                maxNum = max(maxNum, sum);
                left++;
            }
        }
        return maxNum;
            
    }
};
