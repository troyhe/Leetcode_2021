class Solution {
    int maxLength;
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& length, int row, int col){
        if (length[row][col] > 0) return length[row][col];
        int curLength = 0;
        if (row > 0 && matrix[row-1][col] > matrix[row][col]) curLength = max(curLength, dfs(matrix, length, row-1, col));
        if (row + 1 < matrix.size() && matrix[row+1][col] > matrix[row][col]) curLength = max(curLength, dfs(matrix, length, row+1, col));
        if (col > 0 && matrix[row][col-1] > matrix[row][col]) curLength = max(curLength, dfs(matrix, length, row, col-1));
        if (col + 1 < matrix[0].size() && matrix[row][col+1] > matrix[row][col]) curLength = max(curLength, dfs(matrix, length, row, col+1));
        length[row][col] = curLength + 1;
        maxLength = max(maxLength, curLength + 1);
        return curLength + 1;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int row = matrix.size();
        if (row == 0) return 0;
        int col = matrix[0].size();
        if (col == 0) return 0;
        vector<vector<int>> length(row, vector<int>(col, 0));
        maxLength = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                dfs(matrix, length, i, j); 
            }
        }
        return maxLength;
    }
};
