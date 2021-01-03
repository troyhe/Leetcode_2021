class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for (vector<int>& tuple: updates){
            ans[tuple[0]] += tuple[2];
            if (tuple[1] != length - 1) ans[tuple[1] + 1] -= tuple[2];
        }
        partial_sum(ans.begin(), ans.end(), ans.begin());
        return ans;
    }
};
