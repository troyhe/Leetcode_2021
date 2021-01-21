class Solution {
    void dfs(vector<vector<int>>& matrix, vector<vector<bool>>& ocean, int row, int col){
        if (ocean[row][col]) return;
        ocean[row][col] = true;
        if (row > 0 && matrix[row-1][col] >= matrix[row][col]) dfs(matrix, ocean, row-1, col);
        if (row + 1 < matrix.size() && matrix[row+1][col] >= matrix[row][col]) dfs(matrix, ocean, row+1, col);
        if (col > 0 && matrix[row][col-1] >= matrix[row][col]) dfs(matrix, ocean, row, col-1);
        if (col + 1 < matrix[0].size() && matrix[row][col+1] >= matrix[row][col]) dfs(matrix, ocean, row, col+1);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int row = matrix.size();
        if (row == 0) return ans;
        int col = matrix[0].size();
        if (col == 0) return ans;
        vector<vector<bool>> pacific(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++){
            dfs(matrix, pacific, i, 0);
        }
        for (int i = 0; i < col; i++){
            dfs(matrix, pacific, 0, i);
        }
        vector<vector<bool>> atlantic(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++){
            dfs(matrix, atlantic, i, col-1);
        }
        for (int i = 0; i < col; i++){
            dfs(matrix, atlantic, row-1, i);
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (pacific[i][j] && atlantic[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
