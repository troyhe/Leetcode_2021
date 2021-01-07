class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> dicT;
        for (char c: t) dicT[c]++;
        int left = 0;
        int right = 0;
        vector<int> ans = {INT_MAX,0,0};
        int required = dicT.size();
        int formed = 0;
        // [left, right]
        unordered_map<char, int> dicS;
        while (right < s.length()){
            dicS[s[right]]++;
            if (dicT[s[right]] > 0 && dicS[s[right]] == dicT[s[right]]){
                formed ++;
            }
            while (formed == required && left <= right){
                if (right - left + 1 < ans[0]){
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }
                dicS[s[left]]--;
                if (dicT[s[left]] > 0 && dicT[s[left]] > dicS[s[left]]){
                    formed --;
                }
                left++;
            }
            right++;
        }
        return (ans[0] == INT_MAX)?"":s.substr(ans[1], ans[0]);
    }
};
