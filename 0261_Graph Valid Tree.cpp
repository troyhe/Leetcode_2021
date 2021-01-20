class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (n != edges.size() + 1) return false;
        vector<vector<int>> adjacencyList(n);
        for (vector<int> edge: edges){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
        }
        unordered_set<int> seen;
        queue<int> q;
        seen.insert(0);
        q.push(0);
        while (!q.empty()){
            int node = q.front();
            q.pop();
            for (int neighbor: adjacencyList[node]){
                if (seen.count(neighbor)) continue;
                seen.insert(neighbor);
                q.push(neighbor);
            }
        }
        return seen.size() == n;
    }
};
