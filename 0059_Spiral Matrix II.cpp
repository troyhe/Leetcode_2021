class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int r1 = 0;
        int r2 = n - 1;
        int c1 = 0;
        int c2 = n - 1;
        vector<vector<int>> ans(n, vector<int>(n));
        int num = 1;
        while (r1 <= r2 && c1 <= c2){
            for (int i = c1; i <= c2; i++) ans[r1][i] = num++;
            for (int i = r1 + 1; i <= r2; i++) ans[i][c2] = num++;
            if (r2 > r1) for (int i = c2 - 1; i >= c1; i--) ans[r2][i] = num++;
            if (c2 > c1) for (int i = r2 - 1; i >= r1 + 1; i--) ans[i][c1] = num++;
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ans;
    }
};
