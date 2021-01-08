class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length()) return false;
        if (!s1.length()) return s2 == s3;
        if (!s2.length()) return s1 == s3;
        vector<vector<bool>> isEqual(s1.length() + 1, vector<bool>(s2.length() + 1, false));
        isEqual[0][0] = true;
        for (int i = 0; i < s1.length() + 1; i++){
            for (int j = 0; j < s2.length() + 1; j++){
                if (i == 0 && j == 0) continue;
                if (i == 0){
                    isEqual[i][j] = isEqual[i][j-1] && s2[j-1] == s3[i+j-1];
                } else if (j == 0){
                    isEqual[i][j] = isEqual[i-1][j] && s1[i-1] == s3[i+j-1];
                } else {
                    isEqual[i][j] = (isEqual[i-1][j] && s1[i-1] == s3[i+j-1])||(isEqual[i][j-1] && s2[j-1] == s3[i+j-1]);
                }
            }
        }
        return isEqual[s1.length()][s2.length()];
    }
};
