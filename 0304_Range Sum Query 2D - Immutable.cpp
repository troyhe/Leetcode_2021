class NumMatrix {
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        sum.clear();
        int row = matrix.size();
        if (row == 0) return;
        int col = matrix[0].size();
        if (col == 0) return;
        sum.resize(row+1, vector<int>(col+1, 0));
        for (int i = 1; i < row + 1; i++){
            int rowSum = 0;
            for (int j = 1; j < col + 1; j++){
                rowSum += matrix[i-1][j-1];
                sum[i][j] = sum[i-1][j] + rowSum;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1] + sum[row1][col1] - sum[row2+1][col1] - sum[row1][col2+1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
