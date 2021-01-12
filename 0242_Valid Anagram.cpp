class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> dic;
        for (char c: s) dic[c]++;
        for (char c: t) dic[c]--;
        for (auto it: dic){
            if (it.second != 0) return false;
        }
        return true;
    }
};
