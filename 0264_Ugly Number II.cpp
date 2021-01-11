class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ans;
        ans.push_back(1);
        int twoPointer = 0;
        int threePointer = 0;
        int fivePointer = 0;
        for (int i = 1; i < n; i++){
            int next = min(ans[twoPointer]*2, ans[threePointer]*3);
            next = min(next, ans[fivePointer]*5);
            ans.push_back(next);
            if (next == ans[twoPointer]*2) twoPointer++;
            if (next == ans[threePointer]*3) threePointer++;
            if (next == ans[fivePointer]*5) fivePointer++;
        }
        return ans[n-1];
    }
};
