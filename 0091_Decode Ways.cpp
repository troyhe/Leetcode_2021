class Solution {
    int numDecodeHelper(string s){
        if (s.length() == 1 && s[0] != '0') return 1;
        if (s.length() == 2 && s[0] != '0' && stoi(s) <= 26) return 1;
        return 0;
    }
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.length() == 1) return numDecodeHelper(s);
        vector<int> num(s.length()+1, 0);
        num[0] = 1;
        num[1] = numDecodeHelper(s.substr(0,1));
        for (int i = 2; i <= s.length(); i++){
            num[i] = numDecodeHelper(s.substr(i-2,2))*num[i-2] + numDecodeHelper(s.substr(i-1,1))*num[i-1];
        }
        return num[s.length()];
    }
};
