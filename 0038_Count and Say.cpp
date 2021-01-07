class Solution {
    string countHelper(string s){
        string ans = "";
        char cur = s[0];
        int length = 1;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == cur){
                length ++;
            } else {
                ans += to_string(length) + cur;
                cur = s[i];
                length = 1;
            }
        }
        ans += to_string(length) + cur;
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans = "1";
        for (int i = 1; i < n; i++){
            ans = countHelper(ans);
        }
        return ans;
    }
};
