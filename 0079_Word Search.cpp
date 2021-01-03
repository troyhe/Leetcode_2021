class Solution {
    bool existHelper(vector<vector<char>>& board, string& word, int index, int row, int col){
        if (index == word.length()) return true;
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == word[index]){
            char temp = board[row][col];
            board[row][col] = '.';
            if (existHelper(board, word, index + 1, row + 1, col)){
                board[row][col] = temp;
                return true;
            }
            if (existHelper(board, word, index + 1, row - 1, col)){
                board[row][col] = temp;
                return true;
            }
            if (existHelper(board, word, index + 1, row, col + 1)){
                board[row][col] = temp;
                return true;
            }
            if (existHelper(board, word, index + 1, row, col - 1)){
                board[row][col] = temp;
                return true;
            }
            board[row][col] = temp;
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        if (row == 0) return false;
        int col = board[0].size();
        if (col == 0) return false;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (existHelper(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
