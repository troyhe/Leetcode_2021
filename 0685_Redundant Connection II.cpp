class Solution {
    int getRoot(unordered_map<int, int>& prev, int idx){
        if (prev.find(idx) == prev.end()) return idx;
        unordered_set<int> s;
        while (!s.count(idx)){
            s.insert(idx);
            if (prev.find(idx) == prev.end()) return idx;
            idx = prev[idx];
        }
        return idx;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<vector<int>> candidates;
        unordered_map<int, int> prev;
        for (vector<int>& e: edges){
            if (prev.find(e[1]) != prev.end()){
                candidates.push_back({prev[e[1]], e[1]});
                candidates.push_back(e);
            } else {
                prev[e[1]] = e[0];
            }
        }
        int root = getRoot(prev, 1);
        if (candidates.size() > 0){
            vector<vector<int>> next(edges.size()+1);
            for (auto it: prev){
                next[it.second].push_back(it.first);
            }
            vector<bool> seen(edges.size()+1, false);
            queue<int> q;
            q.push(root);
            seen[root] = true;
            int numSeen = 1;
            
            while (!q.empty()){
                int cur = q.front();
                q.pop();
                for (int n: next[cur]){
                    if (!seen[n]){
                        q.push(n);
                        seen[n] = true;
                        numSeen++;
                    }
                }
            }
            if (numSeen == edges.size()) return candidates[1];
            return candidates[0];
        }
        unordered_set<int> cycle;
        while (!cycle.count(root)){
            cycle.insert(root);
            root = prev[root];
        }
        vector<int> ans;
        for (vector<int>& e: edges){
            if (cycle.count(e[0])&& cycle.count(e[1])){
                ans = e;
            } 
        }
        return ans;
    }
};
