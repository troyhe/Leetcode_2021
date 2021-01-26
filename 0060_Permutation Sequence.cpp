class Solution {
    int factorial(int x){
        if (x <= 1) return 1;
        return x*factorial(x-1);
    }
public:
    string getPermutation(int n, int k) {
        string ans = "";
        vector<int> digit(n, 0);
        for (int i = 0; i < n; i++) digit[i] = i+1;
        int fact = factorial(n);
        k--;
        while (n > 0){
            fact /= n;
            n--;
            int idx = k / fact;
            k = k % fact;
            ans += '0' + digit[idx];
            digit.erase(digit.begin()+idx);
        }
        return ans;
    }
};
