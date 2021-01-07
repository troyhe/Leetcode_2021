class Solution {
public:
    string intToRoman(int num) {
        vector<string> thousands = {"", "M", "MM", "MMM"};
        vector<string> hundreds = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 
        vector<string> tens = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        vector<string> ones = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        
        int thousand = num / 1000;
        int hundred = (num % 1000) / 100;
        int ten = (num % 100) / 10;
        int one = num % 10;
        string ans = thousands[thousand] + hundreds[hundred] + tens[ten] + ones[one];
        return ans;
    }
};
