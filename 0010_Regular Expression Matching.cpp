class Solution {
    bool isMatchHelper(const string& s, const string& p, int sIdx, int pIdx){
        if (pIdx == p.length() && sIdx == s.length()) return true;
        if (pIdx == p.length()) return false;
        bool firstMatch = sIdx != s.length() && (s[sIdx] == p[pIdx] || p[pIdx] == '.');
        if (p.length() > pIdx + 1 && p[pIdx+1] == '*'){
            return isMatchHelper(s, p, sIdx, pIdx + 2) || (firstMatch && isMatchHelper(s, p, sIdx + 1, pIdx));
        } else {
            return firstMatch && isMatchHelper(s, p, sIdx + 1, pIdx + 1);
        }
    }
public:
    bool isMatch(string s, string p) {
        //return isMatchHelper(s, p, 0, 0);
        int sLen = s.length() + 1;
        int pLen = p.length() + 1;
        vector<vector<int>> dp(sLen, vector<int>(pLen, false));
        dp[sLen-1][pLen-1] = true;
        for (int i = sLen - 1; i >= 0; i--){
            for (int j = pLen - 2; j >= 0; j--){
                bool firstMatch = i != s.length() && (s[i] == p[j] || p[j] == '.');
                if (j != p.length() - 1 && p[j+1] == '*'){
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
