class Solution {
    class DSU{
        vector<int> parent;
        vector<int> rank;
        int size;
    public:
        DSU(){
            size = 4000;
            parent.resize(size, 0);
            for (int i = 0; i < size; i++) parent[i] = i;
            rank.resize(size, 0);
        }
        
        int find(int x){
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool unionFind(int x, int y){
            int xr = find(x);
            int yr = find(y);
            if (xr == yr) return false;
            if (rank[xr] < rank[yr]) parent[xr] = yr;
            else if (rank[xr] > rank[yr]) parent[yr] = xr;
            else {
                rank[xr]++;
                parent[yr] = xr;
            }
            return false;
        }
    };
public:
    bool areSentencesSimilarTwo(vector<string>& words1, vector<string>& words2, vector<vector<string>>& pairs) {
        if (words1.size() != words2.size()) return false;
        int ID = 1;
        unordered_map<string, int> wordToID;
        DSU dsu;
        for (vector<string> pair: pairs){
            if (wordToID.find(pair[0]) == wordToID.end()){
                wordToID[pair[0]] = ID++;
            }
            if (wordToID.find(pair[1]) == wordToID.end()){
                wordToID[pair[1]] = ID++;
            }
            dsu.unionFind(wordToID[pair[0]], wordToID[pair[1]]);
        }
        for (int i = 0; i < words1.size(); i++){
            int id1 = wordToID[words1[i]];
            int id2 = wordToID[words2[i]];
            if (words1[i] == words2[i]) continue;
            if (id1 * id2 == 0) return false;
            if (dsu.find(id1) != dsu.find(id2)) return false;
        }
        return true;
    }
};
