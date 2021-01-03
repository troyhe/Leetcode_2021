class Solution {
    void helper(vector<vector<int>>& ans, vector<int>& cur, vector<int>& nums, int idx){
        ans.push_back(cur);
        for (int i = idx; i < nums.size(); i++){
            if (i != idx && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            helper(ans, cur, nums, i + 1);
            cur.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        helper(ans, cur, nums, 0);
        return ans;
    }
};
