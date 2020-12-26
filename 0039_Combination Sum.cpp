class Solution {
    void combinationSumHelper(vector<vector<int>>& res, vector<int>& candidates, vector<int> &current, int target, int startIdx) {
        if (target < 0) return;
        if (target == 0){
            res.push_back(current);
            return;
        }
        for (int i = startIdx; i < candidates.size(); i++){
            current.push_back(candidates[i]);
            combinationSumHelper(res, candidates, current, target - candidates[i], i);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> current;
        combinationSumHelper(ans, candidates, current, target, 0);
        return ans;
    }
};
