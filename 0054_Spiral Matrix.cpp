class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r1 = 0;
        int r2 = matrix.size() - 1;
        int c1 = 0;
        int c2 = matrix[0].size() - 1;
        vector<int> ans;
        while (r1 <= r2 && c1 <= c2){
            for (int i = c1; i <= c2; i++) ans.push_back(matrix[r1][i]);
            for (int i = r1 + 1; i <= r2; i++) ans.push_back(matrix[i][c2]);
            if (r2 > r1) for (int i = c2 - 1; i >= c1; i--) ans.push_back(matrix[r2][i]);
            if (c2 > c1) for (int i = r2 - 1; i >= r1 + 1; i--) ans.push_back(matrix[i][c1]);
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};
