class Solution {
    void combinationSum3Helper(vector<vector<int>>& ans, vector<int>& current, int k, int n, int start){      
        if (n == 0 && k == 0){
            ans.push_back(current);
            return;
        }
        if (n <= 0 || k <= 0) return;
        for (int i = start; i < 10; i++){
            current.push_back(i);
            combinationSum3Helper(ans, current, k-1, n-i, i+1);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        combinationSum3Helper(ans, current, k, n, 1);
        return ans;
    }
};
