class Solution {
    struct cmpr{
        bool operator() (const string& s1, const string& s2){
            return s1 + s2 > s2 + s1;
        }
    };
public:
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for (int n: nums) ans.push_back(to_string(n));
        sort(ans.begin(), ans.end(), cmpr());
        string res = "";
        if (ans[0] == "0") return "0";
        for (string& r: ans) res += r;
        return res;
    }
};
