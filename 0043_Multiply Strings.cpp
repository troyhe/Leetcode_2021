class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        vector<int> result(len1 + len2, 0);
        for (int i = len1 - 1; i >= 0; i--){
            for (int j = len2 - 1; j >= 0; j--){
                int product = (num1[i] - '0')*(num2[j] - '0');
                result[i+j+1] += product % 10;
                result[i+j] += product /10;
            }
        }
        string ans = "";
        int carry = 0;
        int digit = 0;
        for (int i = len1 + len2 - 1; i >= 0; i--){
            result[i] += carry;
            if (result[i] >= 10){
                digit = result[i] % 10;
                carry = result[i] / 10;
            } else {
                digit = result[i];
                carry = 0;
            }
            ans = (char)('0' + digit) + ans;
        }
        while (ans.size() > 1 && ans[0] == '0') ans = ans.substr(1);
        return ans;
    }
};
