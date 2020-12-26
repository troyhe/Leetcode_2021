class Solution {
public:
    void helper(vector<vector<int>>& ans, vector<int>& current, vector<int>& candidates, int begin, int target){
        if (target == 0){
            ans.push_back(current);
            return;
        }
        for (int i = begin; i < candidates.size(); i++){
            // The most important part for removing duplicates
            if (i != begin && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) return;
            else {
                current.push_back(candidates[i]);
                helper(ans, current, candidates, i+1, target - candidates[i]);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        helper(ans, current, candidates, 0, target);
        return ans;
    }
};
