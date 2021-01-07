class Solution {
    int KMPlookup(string s){
        vector<int> lookupTable(s.length(), 0);
        int now = 0;
        int p = 1;
        while (p < s.length()){
            if (s[now] == s[p]){
                lookupTable[p++] = ++now;   
            } else if (now != 0){
                now = lookupTable[now-1];
            } else{
                lookupTable[p++] = 0;
            }
        }
        return lookupTable[s.length()-1];
    }
public:
    string shortestPalindrome(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());
        temp = s + "#" + temp;
        int n = KMPlookup(temp);
        string suffix = s.substr(n);
        reverse(suffix.begin(), suffix.end());
        return suffix + s;
    }
};
