class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        // Assume s.length() > t.length() without loss of general
        if (t.length() > s.length()) return isOneEditDistance(t, s);
        // if (s == t) return false;
        if (s.length() - t.length() > 1) return false;
        int idx = 0;
        while (idx < t.length()){
            if (s[idx] == t[idx]) idx++;
            else {
                if (s.length() == t.length()) return s.substr(idx+1) == t.substr(idx+1);
                else return s.substr(idx+1) == t.substr(idx);
            }
        }
        return s.length() != t.length();
    }
};
