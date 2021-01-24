class Solution {
    void constructPath(vector<vector<string>>& ans, vector<string>& path, const string& beginWord, const string& current, unordered_map<string, vector<string>>& parent){
        if (current == beginWord){
            ans.push_back(path);
            return;
        }
        for (const string& s: parent[current]){
            path.push_back(s);
            constructPath(ans, path, beginWord, s, parent);
            path.pop_back();
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_map<string, int> dic;
        for (int i = 0; i < wordList.size(); i++){
            dic[wordList[i]] = INT_MAX;
        }
        if (!dic[endWord]) return ans;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dic[beginWord] = 1;
        int length = INT_MAX;
        
        unordered_map<string, vector<string>> parent;
        while (!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            if (level > length){
                break;
            }
            if (s == endWord){
                length = level;
            }
            string neighbor = s;
            for (int i = 0; i < s.length(); i++){
                for (int j = 0; j < 26; j++){
                    neighbor[i] = j + 'a';
                    if (dic.find(neighbor) != dic.end() && dic[neighbor] >= level + 1){
                        if (dic[neighbor] > level + 1) q.push({neighbor, level+1});
                        dic[neighbor] = level + 1;
                        parent[neighbor].push_back(s);
                    }
                }
                neighbor[i] = s[i];
            }
        }
        vector<string> path = {endWord};
        constructPath(ans, path, beginWord, endWord, parent);
        for (vector<string>& path: ans){
            reverse(path.begin(), path.end());
        }
        return ans;
    }
};
