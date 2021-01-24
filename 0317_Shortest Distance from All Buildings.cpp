class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int row = grid.size();
        if (row == 0) return -1;
        int col = grid[0].size();
        if (col == 0) return -1;
        vector<pair<int, int>> buildings;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    buildings.push_back({i, j});
                }
            }
        }
        vector<vector<bool>> reachable(row, vector<bool>(col, true));
        vector<vector<int>> totalDis(row, vector<int>(col, 0));
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < buildings.size(); i++){
            distance.clear();
            distance.resize(row, vector<int>(col, INT_MAX));
            q.push(make_tuple(buildings[i].first, buildings[i].second, 0));
            distance[buildings[i].first][buildings[i].second] = INT_MAX;
            while (!q.empty()){
                tuple<int, int, int> cur = q.front();
                q.pop();
                int x = std::get<0>(cur);
                int y = std::get<1>(cur);
                int dis = std::get<2>(cur);
                if (x - 1 >= 0 && grid[x-1][y] == 0 && distance[x-1][y] > dis + 1){
                    distance[x-1][y] = dis + 1;
                    q.push(make_tuple(x-1, y, dis+1));
                }
                if (x + 1 < row && grid[x+1][y] == 0 && distance[x+1][y] > dis + 1){
                    distance[x+1][y] = dis + 1;
                    q.push(make_tuple(x+1, y, dis+1));
                }
                if (y - 1 >= 0 && grid[x][y-1] == 0 && distance[x][y-1] > dis + 1){
                    distance[x][y-1] = dis + 1;
                    q.push(make_tuple(x, y-1, dis+1));
                }
                if (y + 1 < col && grid[x][y+1] == 0 && distance[x][y+1] > dis + 1){
                    distance[x][y+1] = dis + 1;
                    q.push(make_tuple(x, y+1, dis+1));
                }
            }
            for (int i = 0; i < grid.size(); i++){
                for (int j = 0; j < grid[0].size(); j++){
                    if (distance[i][j] != INT_MAX){
                        totalDis[i][j] += distance[i][j];
                    } else {
                        reachable[i][j] = false;
                    }
                }
            }
        }
        int minDis = INT_MAX;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (reachable[i][j]){
                    minDis = min(minDis, totalDis[i][j]);
                } 
            }
        }
        return (minDis == INT_MAX)? -1: minDis;
    }
};
