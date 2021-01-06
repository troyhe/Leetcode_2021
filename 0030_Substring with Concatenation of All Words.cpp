class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.empty()) return ans;
        unordered_map<string, int> counter;
        for (string& word: words) counter[word]++;
        int len = words[0].length();
        int size = words.size();
        for (int i = 0; i < len; i++){
            unordered_map<string, int> wordsExist;
            int checked = 0;
            for (int j = i; j <= (int) s.length() - len*size; j += len){
                int k = checked;
                for (; k < size; k++){
                    int wordIdx = j + k*len;
                    string temp = s.substr(wordIdx, len);
                    if (counter[temp] == 0) break;                    
                    if (wordsExist[temp] < counter[temp]){
                         wordsExist[temp]++;
                    } else {
                        break;
                    }
                }
                if (k == size){
                    ans.push_back(j);
                    wordsExist[s.substr(j, len)]--;
                    checked = k - 1;
                } else {
                    if (k == 0) checked = 0;
                    else {
                        wordsExist[s.substr(j, len)]--;
                        checked = k - 1;
                    }
                }
            }
        }
        return ans;
    }
};
