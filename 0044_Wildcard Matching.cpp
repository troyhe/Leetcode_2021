class Solution {
public:
    bool isMatch(string s, string p) {
        int pLen = p.length() + 1;
        int sLen = s.length() + 1;
        vector<vector<bool>> dp(pLen, vector<bool>(sLen, false));
        dp[0][0] = true;
        for (int i = 1; i < pLen; i++){
            if (p[i-1] == '*'){
                int j = 0;
                while (j < sLen && !dp[i-1][j]) j++;
                for (; j < sLen; j++) dp[i][j] = true;
            } else {
                for (int j = 1; j < sLen; j++){
                    dp[i][j] = (p[i-1] == s[j-1] || p[i-1] == '?') && dp[i-1][j-1];
                }
            }
        }
        return dp[pLen-1][sLen-1];
    }
};
