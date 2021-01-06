class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int longest = 0;
        int length = 0;
        for (int i = 0; i < s.length(); i++){
            if (dic.find(s[i]) != dic.end() && dic[s[i]] > i - length - 1){
                length = i - dic[s[i]];
                dic[s[i]] = i;
            } else {
                dic[s[i]] = i;
                length++;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};
