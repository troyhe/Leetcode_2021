class Solution {
    unordered_map<char, vector<char>> dic;
    void initialize(){
        for (int i = 2; i <= 6; i++){
            for (int j = 0; j < 3; j++)
            dic['0'+i].push_back('a' + 3*(i-2) + j);
        }
        for (int i = 0; i < 4; i++){
            dic['7'].push_back('p'+i);
        }
        for (int i = 0; i < 3; i++){
            dic['8'].push_back('t'+i);
        }
        for (int i = 0; i < 4; i++){
            dic['9'].push_back('w'+i);
        }
    }
    void letterCombinationsHelper(vector<string> & ans, string cur, const string& digits, int idx){
        if (idx == digits.length()){
            ans.push_back(cur);
            return;
        }
        for (char c: dic[digits[idx]]){
            letterCombinationsHelper(ans, cur+c, digits, idx+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        initialize();
        vector<string> ans;
        if (digits.empty()) return ans;
        string cur = "";
        letterCombinationsHelper(ans, cur, digits, 0);
        return ans;
    }
};
