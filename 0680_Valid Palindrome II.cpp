class Solution {
    bool validPalindromeHelper(string s){
        int left = 0;
        int right = (int) s.length() - 1;
        while (left < right){
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
public:
    bool validPalindrome(string s) {
        int left = 0;
        int right = (int) s.length() - 1;
        while (left < right){
            if (s[left] != s[right]){
                 return validPalindromeHelper(s.substr(left, right - left))|| validPalindromeHelper(s.substr(left + 1, right - left));
            }
            left++;
            right--;
        }
        return true;
    }
};
