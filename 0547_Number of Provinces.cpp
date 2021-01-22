class Solution {
    class DSU {
        vector<int> parent;
        vector<int> rank;
        int numUnion;
    public:
        DSU(int size){
            numUnion = 0;
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
            numUnion ++;
            return true;
        }
        
        int getNumUnion(){
            return numUnion;
        }
    };
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++){
            for (int j = i + 1; j < isConnected.size(); j++){
                if (isConnected[i][j]) dsu.unionfind(i,j);
            }
        }
        return isConnected.size() - dsu.getNumUnion();
    }
};
