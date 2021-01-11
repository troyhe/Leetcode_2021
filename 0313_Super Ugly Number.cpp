class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> pointers(primes.size(), 0);
        vector<int> ans(n, 0);
        ans[0] = 1;
        for (int i = 1; i < n; i++){
            int next = INT_MAX;
            for (int j = 0; j < primes.size(); j++){
                next = min(next, ans[pointers[j]]*primes[j]);
            }
            ans[i] = next;
            for (int j = 0; j < primes.size(); j++){
                if (next == ans[pointers[j]]*primes[j]) pointers[j]++;
            }
        }
        return ans[n-1];
    }
};
