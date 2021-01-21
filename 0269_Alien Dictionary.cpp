class Solution {
    void constructNode(const string& word, vector<int>& degree){
        for (char c: word){
            if (degree[c -'a'] == -1) degree[c -'a'] = 0;
        }
    }
    bool constructGraph(const string& word1, const string& word2, vector<set<int>>& prevList, vector<vector<int>>& nextList, vector<int>& degree){
        bool diff = false;
        for (int i = 0; i < word1.length() && i < word2.length(); i++){
            if (word1[i] != word2[i]){
                if (!prevList[word2[i] - 'a'].count(word1[i] - 'a')){
                    nextList[word1[i] - 'a'].push_back(word2[i] - 'a');
                    prevList[word2[i] - 'a'].insert(word1[i] - 'a');
                    degree[word2[i] - 'a'] += 1;
                }
                diff = true;
                break;
            }
        }
        if (!diff && word2.length() < word1.length()) return false;
        return true;
    }
public:
    string alienOrder(vector<string>& words) {
        vector<int> degree(26, -1);
        vector<set<int>> prevList(26);
        vector<vector<int>> nextList(26);
        string ans = "";
        for (const string& s: words) constructNode(s, degree);
        for (int i = 0; i < (int) words.size() - 1; i++){
            if (!constructGraph(words[i], words[i+1], prevList, nextList, degree)){
                return ans;
            }
        }
        
        queue<int> q;
        int size = 0;
        for (int i = 0; i < 26; i++){
            if (degree[i] == 0) q.push(i);
            if (degree[i] >= 0) size++;
        }
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            ans += (char) ('a' + cur);
            for (int next: nextList[cur]){
                degree[next]--;
                if (degree[next] == 0) q.push(next);
            }
        }
        if (ans.length() == size) return ans;
        return "";
    }
};
