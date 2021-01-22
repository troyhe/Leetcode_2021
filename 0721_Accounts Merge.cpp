class Solution {
    class DSU{
        int size;
        vector<int> parent;
        vector<int> rank;
    public:
        DSU(){
            size = 10000;
            parent.resize(size, 0);
            for (int i = 0; i < size; i++) parent[i] = i;
            rank.resize(size, 0);
        }
        
        int find(int x){
            if (x != parent[x]) parent[x] = find(parent[x]);
            return parent[x];
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> emailToID;
        unordered_map<int, string> IDToName;
        int ID = 0;
        DSU dsu;
        for (vector<string>& account: accounts){
            string name = account[0];
            for (int i = 1; i < account.size(); i++){
                if (emailToID.find(account[i]) == emailToID.end()){
                    emailToID[account[i]] = ID++;
                    IDToName[emailToID[account[i]]] = name;
                }
                dsu.unionfind(emailToID[account[i]], emailToID[account[1]]);
            }
        }
        unordered_map<int, vector<string>> IDToEmails;
        for (auto it: emailToID){
            IDToEmails[dsu.find(it.second)].push_back(it.first);
        }
        vector<vector<string>> ans;
        for (auto it: IDToEmails){
            sort(it.second.begin(), it.second.end());
            it.second.insert(it.second.begin(), IDToName[it.first]);
            ans.push_back(it.second);
        }
        return ans;
    }
};
