class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c){
        int area = 1;
        grid[r][c] = 0;
        if (r - 1 >= 0 && grid[r-1][c] == 1) area += dfs(grid, r-1, c);
        if (r + 1 < grid.size() && grid[r+1][c] == 1) area += dfs(grid, r+1, c);
        if (c - 1 >= 0 && grid[r][c-1] == 1) area += dfs(grid, r, c-1);
        if (c + 1 < grid[0].size() && grid[r][c+1] == 1) area += dfs(grid, r, c+1);
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        int maxlength = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    maxlength = max(maxlength, dfs(grid, i, j));
                }
            }
        }
        return maxlength;
    }
};
