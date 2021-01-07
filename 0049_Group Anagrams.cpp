class Solution {
    string hashStr(string s){
        sort(s.begin(), s.end());
        return s;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dic;
        for (const string& str: strs){
            dic[hashStr(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for (auto it: dic){
            ans.push_back(it.second);
        }
        return ans;
    }
};
