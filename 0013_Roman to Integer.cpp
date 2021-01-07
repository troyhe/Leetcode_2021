class Solution {
public:
    int romanToInt(string s) {
        int val = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == 'M') val += 1000;
            else if (s[i] == 'D') val += 500;
            else if (s[i] == 'C'){
                if (i != s.length() - 1 && (s[i+1] == 'D' || s[i+1] == 'M')) val -= 100;
                else val += 100;
            }
            else if (s[i] == 'L') val += 50;
            else if (s[i] == 'X'){
                if (i != s.length() - 1 && (s[i+1] == 'L' || s[i+1] == 'C')) val -= 10;
                else val += 10;
            }
            else if (s[i] == 'V') val += 5;
            else if (s[i] == 'I'){
                if (i != s.length() - 1 && (s[i+1] == 'X' || s[i+1] == 'V')) val -= 1;
                else val += 1;
            }
        }
        return val;
    }
};
