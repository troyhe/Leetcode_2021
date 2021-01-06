class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        for (char c: s){
            switch (c){
                case '(':
                case '{':
                case '[':
                    parentheses.push(c);
                    break;
                case ')':
                    if (!parentheses.empty() && parentheses.top() == '(') parentheses.pop();
                    else return false;
                    break;
                case ']':
                    if (!parentheses.empty() && parentheses.top() == '[') parentheses.pop();
                    else return false;
                    break;
                case '}':
                    if (!parentheses.empty() && parentheses.top() == '{') parentheses.pop();
                    else return false;  
                    break;
            }
        }
        return parentheses.empty();
    }
};
