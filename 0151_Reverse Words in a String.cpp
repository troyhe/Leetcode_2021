class Solution {
public:
    string reverseWords(string s) {
        istringstream str(s);
        string ans = "";
        string temp;
        while (str >> temp){
            ans = temp + " " + ans;
        }
        if (!ans.empty()) ans = ans.substr(0, ans.length() - 1);
        return ans;
    }
};
