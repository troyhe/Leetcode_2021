class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        if (arr.size() <= 1) return arr.size();
        int maxLen = 1;
        vector<int> len(arr.size(), 1);
        for (int i = 1; i < arr.size(); i++){
            if (i % 2 == 1 && arr[i] < arr[i-1]) len[i] = len[i-1] + 1;
            if (i % 2 == 0 && arr[i] > arr[i-1]) len[i] = len[i-1] + 1;
            maxLen = max(maxLen, len[i]);
        }
        len.clear();
        len.resize(arr.size(), 1);
        for (int i = 1; i < arr.size(); i++){
            if (i % 2 == 0 && arr[i] < arr[i-1]) len[i] = len[i-1] + 1;
            if (i % 2 == 1 && arr[i] > arr[i-1]) len[i] = len[i-1] + 1;
            maxLen = max(maxLen, len[i]);
        }
        return maxLen;
    }
};
