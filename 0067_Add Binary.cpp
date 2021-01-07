class Solution {
public:
    string addBinary(string a, string b) {
        // Ensure that len(a) >= len(b)
        if (a.length() < b.length()) return addBinary(b,a);
        
        string ans = "";
        int carry = 0;
        int digit = 0;
        int lenA = a.length();
        int lenB = b.length();
        while (digit < lenA){
            int current = 0;
            if (digit < lenB) current = b[lenB - 1 - digit] - '0' + a[lenA - 1 - digit]  - '0' + carry;
            else current = a[lenA - 1 - digit]  - '0' + carry;
            if (current >= 2){
                carry = 1;
                current -= 2;
            } else {
                carry = 0;
            }
            ans = (char)('0'+current) + ans;
            digit++;
        }
        if (carry == 1) ans = '1' + ans;
        return ans;
    }
};
