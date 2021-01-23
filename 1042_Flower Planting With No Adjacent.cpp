class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adjacencyList(n);
        for (vector<int>& path: paths){
            adjacencyList[path[0]-1].push_back(path[1]-1);
            adjacencyList[path[1]-1].push_back(path[0]-1);
        }
        vector<int> color(n, 0);
        int uncolored = n;
        queue<int> q;
        int start = 0;
        while (!q.empty() || uncolored > 0){
            if (q.empty()){
                for (; start < n; start++){
                    if (color[start] == 0){
                        q.push(start);
                        break;
                    }
                }
            }
            vector<bool> canColor(4, true);
            int cur = q.front();
            q.pop();
            if (color[cur] != 0) continue;
            for (int neighbor: adjacencyList[cur]){
                if (color[neighbor] == 0){
                    q.push(neighbor);
                } else {
                    canColor[color[neighbor]-1] = false;
                }
            }
            for (int i = 0; i < 4; i++){
                if (canColor[i]){
                    color[cur] = i + 1;
                    uncolored --;
                    break;
                }
            }
        }
        return color;
    }
};
