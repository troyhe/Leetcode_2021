class Solution {
    class DSU {
        vector<int> parent;
        vector<double> weight;
        vector<int> rank;
        public:
        DSU(int size){
            parent.resize(size, 0);
            for (int i = 0; i < size; i++) parent[i] = i;
            weight.resize(size, 1);
            rank.resize(size, 0);
        }
        
        int find(int x){
            if (parent[x] != x){
                weight[x] *= weight[parent[x]];
                parent[x] = find(parent[x]);               
            }
            return parent[x];
        }
        
        double unionFind(int x, int y, double w = 0){
            // Return x/y
            // weight = x/y
            int xr = find(x);
            int yr = find(y);
            if (xr == yr){
                return weight[y]/weight[x];
            }
            if (w == 0) return -1;
            if (rank[xr] > rank[yr]){
                parent[yr] = xr;
                weight[yr] = w / (weight[y]/weight[x]);
            } else if (rank[xr] < rank[yr]){
                parent[xr] = yr;
                weight[xr] = (weight[y]/weight[x])/w;
            } else {
                rank[xr]++;
                parent[yr] = xr;
                weight[yr] = w / (weight[y]/weight[x]);
            }
            return -1;
        }
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        DSU dsu(40);
        int ID = 1;
        unordered_map<string, int> strToID;
        for (int i = 0; i < equations.size(); i++){
            if (strToID.find(equations[i][0]) == strToID.end()){
                strToID[equations[i][0]] = ID++;
            }
            if (strToID.find(equations[i][1]) == strToID.end()){
                strToID[equations[i][1]] = ID++;
            }
            dsu.unionFind(strToID[equations[i][0]], strToID[equations[i][1]], values[i]);
        }
        vector<double> ans(queries.size());
        for (int i = 0; i < queries.size(); i++){
            int id1 = strToID[queries[i][0]];
            int id2 = strToID[queries[i][1]];
            if (id1 * id2 == 0) ans[i] = -1;
            else ans[i] = dsu.unionFind(id1, id2);
        }
        return ans;
    }
};
