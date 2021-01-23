class Solution {
    bool LTDhelper(vector<vector<int>>& adjacencyList, set<int>& path, int source, int destination){
        if (source == destination) return true;
        if (adjacencyList[source].empty()) return false;
        for (int next: adjacencyList[source]){
            if (path.count(next)) return false;
            path.insert(next);
            if (!LTDhelper(adjacencyList, path, next, destination)) return false;
            path.erase(next);
        }
        return true;
    }
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjacencyList(n);
        for (vector<int>& edge: edges){
            adjacencyList[edge[0]].push_back(edge[1]);
        }
        if (!adjacencyList[destination].empty()) return false;
        set<int> path;
        path.insert(source);
        return LTDhelper(adjacencyList, path, source, destination);
    }
};
