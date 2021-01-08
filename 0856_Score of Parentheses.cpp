class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        for (char c: S){
            if (c == '(') s.push(-1);
            else {
                int temp = 0;
                while (!s.empty() && s.top() != -1){
                    temp += s.top();
                    s.pop();
                }
                s.pop();
                if (temp == 0) s.push(1);
                else s.push(temp*2);
            }
        }
        int ans = 0;
        while (!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
