class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, bool> dic;
        for (int i = 0; i < wordList.size(); i++){
            dic[wordList[i]] = true;
        }
        if (!dic[endWord]) return false;
        // if (!dic[beginWord]) return false;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        dic[beginWord] = false;
        while (!q.empty()){
            string s = q.front().first;
            int level = q.front().second;
            q.pop();
            if (s == endWord) return level;
            string neighbor = s;
            for (int i = 0; i < s.length(); i++){
                for (int j = 0; j < 26; j++){
                    neighbor[i] = j + 'a';
                    if (dic.find(neighbor) != dic.end() && dic[neighbor]){
                        q.push({neighbor, level+1});
                        dic[neighbor] = false;
                    }
                }
                neighbor[i] = s[i];
            }
        }
        return 0;
    }
};
