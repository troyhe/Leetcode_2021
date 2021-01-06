class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        unordered_map<char, int> dic;
        int front = 0;
        int back = 0;
        int maxLength = 0;
        for (; back < s.length(); back++){
            if (dic.find(s[back]) == dic.end() && dic.size() == 2){
                // twoChar[1] is to be erased;
                vector<char> twoChar;
                for (auto it: dic){
                    twoChar.push_back(it.first);
                }
                if (dic[twoChar[1]] > dic[twoChar[0]]) swap(twoChar[0], twoChar[1]);
                front = dic[twoChar[1]] + 1;
                dic.erase(twoChar[1]);
                dic[s[back]] = back;
            } else {
                dic[s[back]] = back;
            }
            maxLength = max(maxLength, back - front + 1);
        }
        return maxLength;
    }
};
