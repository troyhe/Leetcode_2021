class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] *= -1;
            else ans[0] = idx + 1;
        }
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] > 0){
                ans[1] = i + 1;
                break;
            }
        }
        return ans;
    }
};
