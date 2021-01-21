class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return vector<int>(1,0);
        vector<vector<int>> adjacencyList(n);
        vector<int> degree(n, 0);
        for (vector<int>& edge: edges){
            adjacencyList[edge[0]].push_back(edge[1]);
            adjacencyList[edge[1]].push_back(edge[0]);
            degree[edge[0]]++;
            degree[edge[1]]++;
        }
        vector<int> leaves;
        for (int i = 0; i < n; i++){
            if (degree[i] == 1) leaves.push_back(i);
        }
        int remainNodes = n;
        while (remainNodes > 2){
            vector<int> newLeaves;
            for (int l: leaves){
                for (int neighbor: adjacencyList[l]){
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) newLeaves.push_back(neighbor);
                }
            }
            remainNodes -= leaves.size();
            leaves = newLeaves;
        }
        return leaves;
    }
};
