class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLength = 0;
        stack<int> parenthesis;
        parenthesis.push(-1);
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '('){
                parenthesis.push(i);
            } else {
                parenthesis.pop();
                if (parenthesis.empty()){
                    parenthesis.push(i);
                } else {
                    maxLength = max(maxLength, i - parenthesis.top());
                }
            }
        }
        return maxLength;
    }
};
