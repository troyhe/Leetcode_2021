class Solution {
    bool isSubsequenceHelper(string& s, string& t, int sIdx, int tIdx){
        if (sIdx == s.length()) return true;
        if (tIdx == t.length()) return false;
        if (s[sIdx] == t[tIdx]) return isSubsequenceHelper(s, t, sIdx + 1, tIdx + 1);
        return isSubsequenceHelper(s, t, sIdx, tIdx + 1);
    }
public:
    bool isSubsequence(string s, string t) {
        return isSubsequenceHelper(s, t, 0, 0);
    }
};
