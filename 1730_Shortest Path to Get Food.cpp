class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        queue<tuple<int,int,int>> path;
        //tuple<int,int,int> start = {0, 0, 0};
        int xStart, yStart;
        bool find = false;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == '*'){
                    xStart = i;
                    yStart = j;
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        path.push({xStart, yStart, 0});
        while (!path.empty()){
            tuple<int,int,int> cur = path.front();
            path.pop();
            int x = get<0>(cur);
            int y = get<1>(cur);
            int level = get<2>(cur);
            //if (grid[x][y] == '#') return level;
            //grid[x][y] = 'X';
            if (x - 1 >= 0 && grid[x-1][y] != 'X'){
                if (grid[x-1][y] == '#') return level+1;
                grid[x-1][y] = 'X';
                path.push(make_tuple(x-1, y, level+1));
            }
            if (x + 1 < grid.size() && grid[x+1][y] != 'X'){
                if (grid[x+1][y] == '#') return level+1;
                grid[x+1][y] = 'X';
                path.push(make_tuple(x+1, y, level+1));
            }
            if (y - 1 >= 0 && grid[x][y-1] != 'X'){
                if (grid[x][y-1] == '#') return level+1;
                grid[x][y-1] = 'X';
                path.push(make_tuple(x, y-1, level+1));
            }
            if (y + 1 < grid[0].size() && grid[x][y+1] != 'X'){
                if (grid[x][y+1] == '#') return level+1;
                grid[x][y+1] = 'X';
                path.push(make_tuple(x, y+1, level+1));
            }
        }
        return -1;
    }
};
