class Solution {
    string hashHelper(string s){
        if (s.empty()) return s;
        int diff = s[0] - 'a';
        for (char& c: s){
            c -= diff;
            if (c < 'a') c+= 26;
        }
        return s;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> dic;
        for (string& s: strings){
            dic[hashHelper(s)].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto it: dic){
            ans.push_back(it.second);
        }
        return ans;
    }
};
