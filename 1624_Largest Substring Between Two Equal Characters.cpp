class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int length = -1;
        vector<int> characters(26, -1);
        for (int i = 0; i < s.length(); i++){
            if (characters[s[i] - 'a'] >= 0){
                length = max(length, i - characters[s[i] - 'a'] - 1);
            } else {
                characters[s[i] - 'a'] = i;
            }
            
        }
        return length;
    }
};
