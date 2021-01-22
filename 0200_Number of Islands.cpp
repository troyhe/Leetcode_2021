class Solution {
    class DSU{
        vector<int> parent;
        vector<int> rank;
        int numIslands;
    public:
        DSU(int num){
            numIslands = 0;
            parent.resize(num, 0);
            for (int i = 0; i < num; i++) parent[i] = i;
            rank.resize(num, 0);
        }
        
        int find(int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        bool unionFind(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr) return false;
            if (rank[xr] < rank[yr]) parent[xr] = yr;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else {
                parent[yr] = xr;
                rank[xr]++;
            }
            numIslands --;
            return true;
        }
        
        int getNumIslands(){
            return numIslands;
        }
    };
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int col = grid[0].size();
        if (col == 0) return 0;
        DSU dsu(row*col);
        int numIslands = 0;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == '1'){
                    numIslands ++;
                    if (i - 1 >= 0 && grid[i-1][j] == '1') dsu.unionFind(i * col + j, (i-1) * col + j);
                    if (i + 1 < row && grid[i+1][j] == '1') dsu.unionFind(i * col + j, (i+1) * col + j);
                    if (j - 1 >= 0 && grid[i][j-1] == '1') dsu.unionFind(i * col + j, i * col + j - 1);
                    if (j + 1 < col && grid[i][j+1] == '1') dsu.unionFind(i * col + j, i * col + j + 1);
                    // grid[i][j] = '0';
                }
            }
        }
        numIslands += dsu.getNumIslands();
        return numIslands;
    }
};
