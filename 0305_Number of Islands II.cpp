class Solution {
    class DSU{
        vector<int> parent;
        vector<int> rank;
        vector<vector<bool>> grid;
        int numIslands;
        int row;
        int col;
    public:
        DSU(int m, int n){
            row = m;
            col = n;
            numIslands = 0;
            parent.resize(m * n, 0);
            for (int i = 0; i < m * n; i++) parent[i] = i;
            rank.resize(m * n, 0);
            grid.resize(m, vector<bool>(n, false));
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
        
        int addIsland(int i, int j){
            if (grid[i][j]) return numIslands;
            numIslands ++;
            grid[i][j] = true;
            if (i - 1 >= 0 && grid[i-1][j]) unionFind(i * col + j, (i-1) * col + j);
            if (i + 1 < row && grid[i+1][j]) unionFind(i * col + j, (i+1) * col + j);
            if (j - 1 >= 0 && grid[i][j-1]) unionFind(i * col + j, i * col + j - 1);
            if (j + 1 < col && grid[i][j+1]) unionFind(i * col + j, i * col + j + 1);
            return numIslands;
        }
        
        int getNumIslands(){
            return numIslands;
        }
    };
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU dsu(m, n);
        vector<int> ans(positions.size());
        for (int i = 0; i < positions.size(); i++){
            ans[i] = dsu.addIsland(positions[i][0], positions[i][1]);
        }
        return ans;
    }
};
