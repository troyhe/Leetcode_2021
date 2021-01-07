class Solution {
public:   
    string convert(string s, int numRows) {
        if (numRows <= 1 || numRows > s.length()) return s;
        string ans = "";
        for (int i = 0; i < numRows; i++){
            for (int j = 0; i + j < s.length(); j += 2*numRows - 2){
                ans += s[i + j];
                if (i != 0 && i != numRows - 1 && j + 2*numRows - 2 - i < s.length()){
                    ans += s[j + 2*numRows - 2 - i];
                }
            }
        }
        return ans;
    }
};
