class Solution {
    void flip(vector<vector<char>>& board, int row, int col){
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size() && board[row][col] == 'O'){
            board[row][col] = 'N';
            flip(board, row, col-1);
            flip(board, row, col+1);
            flip(board, row-1, col);
            flip(board, row+1, col);
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // traverse border O to N
        int r = board.size();
        if (r == 0) return;
        int c = board[0].size();
        if (c == 0) return;
        for (int i = 0; i < c; i++){
            flip(board, 0, i);
            flip(board, r-1, i);
        }
        for (int i = 1; i < r - 1; i++){
            flip(board, i, 0);
            flip(board, i, c-1);
        }
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if (board[i][j] == 'N'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
