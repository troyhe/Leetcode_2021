class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length()) return false;
        if (s1.length() == 1) return s1 == s2;
        int len = s1.length();
        vector<vector<vector<bool>>> dp(len, vector<vector<bool>>(len, vector<bool>(len, false)));
        for (int i = 0; i < len; i++){
            for (int j = 0; j < len; j++){
                dp[0][i][j] = s1[i] == s2[j];
            }
        }
        for (int k = 1; k < len; k++){
            for (int i = 0; i < len - k; i++){
                for (int j = 0; j < len - k; j++){
                    for (int n = 0; n < k; n++){
                        if (dp[n][i][j] && dp[k-n-1][i+n+1][j+n+1]){
                            dp[k][i][j] = true;
                            break;
                        }
                        
                        if (dp[n][i][j+k-n] && dp[k-n-1][i+n+1][j]){
                            dp[k][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[len-1][0][0];
    }
};
