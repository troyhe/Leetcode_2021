class Solution {
    int checkNeighbour(int i, int j, int row, int col, vector<vector<int>>& board){
        int liveNeighbour = 0;
        if (i >= 1 && board[i-1][j] % 2 == 1) liveNeighbour++;
        if (i >= 1 && j >= 1 && board[i-1][j-1] % 2 == 1) liveNeighbour++;
        if (i >= 1 && j < col - 1 &&board[i-1][j+1] % 2 == 1) liveNeighbour++;
        if (j >= 1 && board[i][j-1] % 2 == 1) liveNeighbour++;
        if (j >= 1 && i < row - 1 && board[i+1][j-1] % 2 == 1) liveNeighbour++;
        if (i < row - 1 && board[i+1][j] % 2 == 1) liveNeighbour++;
        if (j < col - 1 && board[i][j+1] % 2 == 1) liveNeighbour++;
        if (j < col - 1 && i < row -1 && board[i+1][j+1] % 2 == 1) liveNeighbour++;
        return liveNeighbour;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                int n = checkNeighbour(i, j, row, col, board);
                if (board[i][j] == 0 && n == 3) board[i][j] = 2;
                if (board[i][j] == 1 && (n < 2 || n > 3)) board[i][j] = 3;
            }
        }
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (board[i][j] == 3) board[i][j] = 0;
                if (board[i][j] == 2) board[i][j] = 1;
            }
        }
    }
};
