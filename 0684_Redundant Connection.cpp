class Solution {
    class DSU {
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(int size){
            parent.resize(size, 0);
            for (int i = 0; i < size; i++) parent[i] = i;
            rank.resize(size, 0);
        }
        
        int find(int i){
            if (parent[i] != i){
                parent[i] = find(parent[i]);
            }
            return parent[i];
        }
        
        bool unionfind(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr) return false;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else if (rank[xr] < rank[yr]) parent[xr] = yr;
            else {
                rank[xr]++;
                parent[yr] = xr;
            }
            return true;
        }
    };
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size());
        for (vector<int>& e: edges){
            if (!dsu.unionfind(e[0]-1, e[1]-1)){
                return e;
            }
        }
        return vector<int>();
    }
};
