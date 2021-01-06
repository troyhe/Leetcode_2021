class Solution {
    void generateParenthesisHelper(vector<string>& ans, string cur, int open, int close, int n){
        if (close == n){
            ans.push_back(cur);
            return;
        }
        if (open > close) generateParenthesisHelper(ans, cur + ')', open, close+1, n);
        if (open < n) generateParenthesisHelper(ans, cur + '(', open+1, close, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        generateParenthesisHelper(ans, "", 0, 0, n);
        return ans;
    }
};
