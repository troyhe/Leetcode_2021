class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int row = rooms.size();
        int col = rooms[0].size();
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (rooms[i][j] == 0){
                    q.push(make_tuple(i, j, 0));
                }
            }
        }
        while (!q.empty()){
            tuple<int, int, int> cur = q.front();
            q.pop();
            int x = std::get<0>(cur);
            int y = std::get<1>(cur);
            int dis = std::get<2>(cur);
            if (x - 1 >= 0 && rooms[x-1][y] != -1 && rooms[x-1][y] > dis + 1){
                rooms[x-1][y] = dis + 1;
                q.push(make_tuple(x-1, y, dis+1));
            }
            if (x + 1 < row && rooms[x+1][y] != -1 && rooms[x+1][y] > dis + 1){
                rooms[x+1][y] = dis + 1;
                q.push(make_tuple(x+1, y, dis+1));
            }
            if (y - 1 >= 0 && rooms[x][y-1] != -1 && rooms[x][y-1] > dis + 1){
                rooms[x][y-1] = dis + 1;
                q.push(make_tuple(x, y-1, dis+1));
            }
            if (y + 1 < col && rooms[x][y+1] != -1 && rooms[x][y+1] > dis + 1){
                rooms[x][y+1] = dis + 1;
                q.push(make_tuple(x, y+1, dis+1));
            }
        }
    }
};
