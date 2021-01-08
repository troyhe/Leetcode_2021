class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        int begin = 0;
        int end = 0;
        for (; end < s.size(); end++){
            if (s[end] == ' '){
                reverse(s.begin() + begin, s.begin()+end);
                begin = end + 1;
            }
        }
        reverse(s.begin() + begin, s.end());
    }
};
