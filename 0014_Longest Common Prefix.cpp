class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        if (strs.size() <= 0) return prefix;
        for (int i = 0; i < strs[0].length(); prefix += strs[0][i], i++){
            for (string &s: strs){
                if (s.length() <= i || strs[0][i] != s[i]) return prefix;
            }
        }
        return prefix;
    }
};
