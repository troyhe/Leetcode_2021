class Solution {
public:
    int numTrees(int n) {
        if (n == 0) return 0;
        vector<int> dp(n+1, 1);
        for (int i = 1; i <= n; i++){
            int sum = 0;
            for (int j = 1; j <= i; j++){
                sum += dp[j-1] * dp[i-j];
            }
            dp[i] = sum;
        }
        return dp[n];
    }
};
