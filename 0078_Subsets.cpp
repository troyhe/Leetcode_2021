class Solution {
    void subsetsHelper(vector<vector<int>> &ans, vector<int>& nums, vector<int> &current, int beginIdx, int n){
        ans.push_back(current);   
        for (int i = beginIdx; i < n; i++){
            if (i != beginIdx && nums[i] == nums[i-1]) continue;
            current.push_back(nums[i]);
            subsetsHelper(ans, nums, current, i+1, n);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> current;
        sort(nums.begin(), nums.end());
        subsetsHelper(ans, nums, current, 0, nums.size());
        return ans;
    }
};
