class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        int n = org.size();
        //if (n == 1) return false;
        if (seqs.empty()) return false;
        vector<set<int>> prevList(n);
        vector<set<int>> nextList(n);
        vector<int> degree(n, 0);
        for (vector<int>& seq: seqs){
            for (int i = 0; i < seq.size(); i++){
                if (seq[i] > n || seq[i] <= 0 || (i != seq.size() - 1 && (seq[i+1] > n || seq[i+1] <= 0))) return false;
                if (i == seq.size() - 1) break;
                if (!nextList[seq[i]-1].count(seq[i+1]-1)){
                    nextList[seq[i]-1].insert(seq[i+1]-1);
                    prevList[seq[i+1]-1].insert(seq[i]-1);
                    degree[seq[i+1]-1]++;
                }
            }
        }
        queue<int> noIncomingEdge;
        for (int i = 0; i < n; i++){
            if (degree[i] == 0) noIncomingEdge.push(i);
        }
        int idx = 0;
        while (!noIncomingEdge.empty()){
            if (noIncomingEdge.size() != 1) return false;
            int cur = noIncomingEdge.front();
            noIncomingEdge.pop();
            if (idx == n || cur + 1 != org[idx++]) return false;
            for (auto it: nextList[cur]){
                degree[it]--;
                if (degree[it] == 0) noIncomingEdge.push(it);
            }
        }
        return idx == n;
    }
};
