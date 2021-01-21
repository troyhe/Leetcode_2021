class Solution {
    void dfs(int idx, vector<vector<int>> &adjacencyList, vector<bool>& done){
        done[idx] = true;
        for (int neighbor: adjacencyList[idx]){
            if (!done[neighbor]) dfs(neighbor, adjacencyList, done);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacencyList(n);
        for (vector<int>& edge: edges){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        vector<bool> done(n, false);
        int num = 0;
        for (int i = 0; i < n; i++){
            if (!done[i]){
                dfs(i, adjacencyList, done);
                num++;
            }
        }
        return num;
    }
};
