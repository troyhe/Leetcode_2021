class Solution {
    void helper(vector<vector<int>>& ans, vector<int>& current, vector<vector<int>>& graph, int cur){
        if (cur == graph.size() - 1){
            ans.push_back(current);
            return;
        }
        for (int neighbor: graph[cur]){
            current.push_back(neighbor);
            helper(ans, current, graph, neighbor);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> current(1,0);
        vector<vector<int>> ans;
        helper(ans, current, graph, 0);
        return ans;
    }
};
