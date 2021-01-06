class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k == 0) return 0;
        unordered_map<char, int> dic;
        int front = 0;
        int back = 0;
        int maxLength = 0;
        for (; back < s.length(); back++){
            if (dic.find(s[back]) == dic.end() && dic.size() == k){
                int toEraseIdx = back;
                for (auto it: dic){
                    toEraseIdx = min(toEraseIdx, it.second);
                }
                front = toEraseIdx + 1;
                dic.erase(s[toEraseIdx]);
                dic[s[back]] = back;
            } else {
                dic[s[back]] = back;
            }
            maxLength = max(maxLength, back - front + 1);
        }
        return maxLength;
    }
};
