class Solution {
    bool isValid(const string& s){
        if (s.length() > 3) return false;
        if (s[0] == '0') return s.length() == 1;
        return stoi(s) <= 255;
    }
    
    string process(const vector<string>& segs){
        string ans = segs[0];
        for (int i = 1; i < 4; i++) ans += "." + segs[i];
        return ans;
    }
    void restoreIpAddressesHelper(vector<string>& ans, vector<string>& segs, const string& s, int start){
        if (segs.size() == 4){
            if (start == s.length()){
                ans.push_back(process(segs));
            } else return;
        }
        int maxPos = (s.length() - start > 3)?3:s.length() - start;
        for (int i = 1; i <= maxPos; i++){
            string str = s.substr(start, i);
            if (isValid(str)){
                segs.push_back(str);
                restoreIpAddressesHelper(ans, segs, s, start + i);
                segs.pop_back();
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> segs;
        restoreIpAddressesHelper(ans, segs, s, 0);
        return ans;
    }
};
