class Solution {
    vector<int> getNext(const string& needle){
        vector<int> next;
        next.push_back(0);
        int now = 0;
        int x = 1;
        while (x < needle.length()){
            if (needle[x] == needle[now]){
                now++;
                x++;
                next.push_back(now);
            } else if (now != 0){
                now = next[now-1];
            } else {
                next.push_back(0);
                x++;
            }
        }
        return next;
    }
public:
    int strStr(string haystack, string needle) {
        // https://www.zhihu.com/question/21923021/answer/1032665486
        if (needle.empty()) return 0;
        vector<int> next = getNext(needle);
        int hIdx = 0;
        int nIdx = 0;
        while (hIdx < haystack.length()){
            if (haystack[hIdx] == needle[nIdx]){
                hIdx++;
                nIdx++;
            } else if (nIdx > 0){
                nIdx = next[nIdx-1];
            } else {
                hIdx++;
            }
            
            if (nIdx == needle.length()) return hIdx - nIdx;
        }
        return -1;
    }
};
