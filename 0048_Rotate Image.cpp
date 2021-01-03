class Solution {
    void reverse(vector<vector<int>>& matrix){
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size()/2; j++){
                swap(matrix[i][j], matrix[i][matrix[0].size() - 1 - j]);
            }
        }
    }
    
public:
    void rotate(vector<vector<int>>& matrix) {
        reverse(matrix);
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size() - i - 1; j++){
                swap(matrix[i][j], matrix[matrix[0].size() - 1 - j][matrix[0].size() - 1 - i]);
            }
        }
    }
};
