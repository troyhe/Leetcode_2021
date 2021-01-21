class Solution {
    void partitionHelper(vector<vector<string>> &ans, vector<vector<bool>>& isPalin, vector<string> &current, const string& s, int start){
        if (start == s.length()){
            ans.push_back(current);
            return;
        }
        for (int i = start; i < s.length(); i++){
            if (s[i] == s[start] && (i - start < 2 || isPalin[start+1][i-1])){
                isPalin[start][i] = true;
                current.push_back(s.substr(start, i - start + 1));
                partitionHelper(ans, isPalin, current, s, i + 1);
                current.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> current;
        vector<vector<bool>> isPalindrome(s.length(), vector<bool>(s.length(), false));
        partitionHelper(ans, isPalindrome, current, s, 0);
        return ans;
    }
};
