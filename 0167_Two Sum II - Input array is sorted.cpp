class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> ans(2, 0);
        while (left < right){
            int sum = numbers[left] + numbers[right];
            if (sum == target){
                ans[0] = left + 1;
                ans[1] = right + 1;
                return ans;
            } else if (sum > target){
                right--;
            } else {
                left++;
            }
        }
        return ans;
    }
};
