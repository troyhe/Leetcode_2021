class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0) return true;
        int n = graph.size();
        vector<int> color(graph.size(), -1);
        queue<int> q;
        // q.push(0);
        // color[0] = 0;
        int colorRemaining = graph.size();
        while (!q.empty() || colorRemaining > 0){
            if (q.empty()){
                for (int i = 0; i < graph.size(); i++){
                    if (color[i] == -1){
                        q.push(i);
                        color[i] = 0;
                        colorRemaining--;
                        break;
                    }
                }
            }
            int cur = q.front();
            q.pop();
            int nextColor;
            if (color[cur] == 0) nextColor = 1;
            else nextColor = 0;
            for (int neighbor: graph[cur]){
                if (color[neighbor] == -1){
                    color[neighbor] = nextColor;
                    q.push(neighbor);
                    colorRemaining--;
                }
                else if (color[neighbor] != nextColor) return false;
                
            }
        }
        return true;
    }
};
