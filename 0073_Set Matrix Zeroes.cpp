class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool rowZero = false;
        bool colZero = false;
        if (matrix.size() == 0) return;
        if (matrix[0].size() == 0) return;
        // the first col
        for (int i = 0; i < matrix.size(); i++){
            if (matrix[i][0] == 0) colZero = true;
        }
        // the first row
        for (int i = 0; i < matrix[0].size(); i++){
            if (matrix[0][i] == 0) rowZero = true;
        }
        
        for (int i = 1; i < matrix.size(); i++){
            for (int j = 1; j < matrix[0].size(); j++){
                if (matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // Set 0s
        for (int i = 1; i < matrix.size(); i++){
            for (int j = 1; j < matrix[0].size(); j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        
        if (rowZero){
            for (int i = 0; i < matrix[0].size(); i++){
                matrix[0][i] = 0;
            }
        }
        if (colZero){
            for (int i = 0; i < matrix.size(); i++){
                matrix[i][0] = 0;
            }
        }
    }
};
