class Solution {
    class DSU {
        vector<int> parent;
        vector<int> rank;
        int numUnion;
    public:
        DSU(int size){
            // The left part of grid[i][j] is 2*(i * n + j)
            // The right part of grid[i][j] is 2*(i * n + j) + 1
            parent.resize(size * size * 2, 0);
            for (int i = 0; i < size* size * 2; i++) parent[i] = i;
            rank.resize(size* size* 2, 0);
            numUnion = 0;
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
            if (rank[xr] > rank[yr]) parent[yr] = xr;
            else if (rank[xr] < rank[yr]) parent[xr] = yr;
            else {
                parent[xr] = yr;
                rank[yr]++;
            }
            numUnion ++;
            return true;
        }
        
        int getUnion(){
            return numUnion;
        }
    };
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DSU dsu(n);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == ' ') dsu.unionFind(2*(i * n + j), 2*(i * n + j)+1);
                if (j > 0) dsu.unionFind(2*(i * n + j)-1, 2*(i * n + j));
                if (i > 0){
                    if (grid[i][j] == '\\' && grid[i-1][j] == '\\'){
                        dsu.unionFind(2*(i * n + j)+1, 2*((i-1) * n + j));
                    } else if (grid[i][j] == '\\'){
                        dsu.unionFind(2*(i * n + j)+1, 2*((i-1) * n + j)+1);
                    } else if (grid[i-1][j] == '\\'){
                        dsu.unionFind(2*(i * n + j), 2*((i-1) * n + j));
                    } else {
                        dsu.unionFind(2*(i * n + j), 2*((i-1) * n + j)+1);
                    }
                }
            }
        }
        return 2*n*n - dsu.getUnion();
    }
};
