class Solution {
    int numDecodeHelper(string s){
        if (s.length() == 1){
            if (s[0] == '0') return 0;
            else if (s[0] == '*') return 9;
            else return 1;
        }
        if (s.length() == 2){
            if (s[0] == '*' && s[1] == '*') return 15;
            else if (s[0] == '*'){
                if (s[1] >= '0' && s[1] <= '6') return 2;
                if (s[1] >= '7' && s[1] <= '9') return 1;
                return 0;
            } else if (s[1] == '*'){
                if (s[0] == '1') return 9;
                if (s[0] == '2') return 6;
                else return 0;
            } else {
                if (s[0] != '0' && stoi(s) <= 26) return 1;
                return 0;
            }
        }
        return 0;
    }
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s.length() == 1) return numDecodeHelper(s);
        vector<int> num(s.length()+1, 0);
        int M = (int)pow(10, 9) + 7;
        num[0] = 1;
        num[1] = numDecodeHelper(s.substr(0,1));
        for (int i = 2; i <= s.length(); i++){
            num[i] = (numDecodeHelper(s.substr(i-2,2))*num[i-2] + numDecodeHelper(s.substr(i-1,1))*num[i-1]) % M;
        }
        return num[s.length()];
    }
};
