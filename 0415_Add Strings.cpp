class Solution {
public:
    string addStrings(string a, string b) {
        if (a.length() < b.length()) return addStrings(b,a);
        string ans = "";
        int carry = 0;
        int digit = 0;
        int lenA = a.length();
        int lenB = b.length();
        while (digit < lenA){
            int current = 0;
            if (digit < lenB) current = b[lenB - 1 - digit] - '0' + a[lenA - 1 - digit]  - '0' + carry;
            else current = a[lenA - 1 - digit]  - '0' + carry;
            carry = current / 10;
            current = current % 10;            
            ans = (char)('0'+current) + ans;
            digit++;
        }
        if (carry > 0) ans = (char)('0'+ carry) + ans;
        return ans;
    }
};
