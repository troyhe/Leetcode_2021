class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        // Construct a monotonic decreasing stack;
        stack<int> monoStack;
        vector<int> ans(T.size(), 0);
        for (int i = 0; i < T.size(); i++){
            while (!monoStack.empty() && T[monoStack.top()] < T[i]){
                int cur = monoStack.top();
                monoStack.pop();
                ans[cur] = i - cur;
            }
            monoStack.push(i);
        }
        return ans;
    }
};
