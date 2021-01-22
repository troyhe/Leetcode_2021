class Solution {
    int dfs(vector<vector<int>>& grid, int r, int c){
        int perimeter = 0;
        grid[r][c] = 2;
        if (r - 1 >= 0){
            if (grid[r-1][c] == 1){
                perimeter += dfs(grid, r-1, c);
            } else if (grid[r-1][c] == 0){
                perimeter += 1;
            }
        } else {
            perimeter += 1;
        }
        if (r + 1 < grid.size()){
            if (grid[r+1][c] == 1){
                perimeter += dfs(grid, r+1, c);
            } else if (grid[r+1][c] == 0){
                perimeter += 1;
            }
        } else {
            perimeter += 1;
        }
        if (c - 1 >= 0){
            if (grid[r][c-1] == 1){
                perimeter += dfs(grid, r, c-1);
            } else if (grid[r][c-1] == 0){
                perimeter += 1;
            }
        } else {
            perimeter += 1;
        }
        if (c + 1 < grid[0].size()){
            if (grid[r][c+1] == 1){
                perimeter += dfs(grid, r, c+1);
            } else if (grid[r][c+1] == 0){
                perimeter += 1;
            }
        } else {
            perimeter += 1;
        }
        return perimeter;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    return dfs(grid,i,j);
                }
            }
        }
        return 0;
    }
};
