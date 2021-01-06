class Solution {
    string int2time(int hour, int min){
        string minStr = (min >= 10)?to_string(min):"0"+to_string(min);
        return to_string(hour)+":"+minStr;
    }
    void readBinaryWatchHelper(vector<string> &ans, int hour, int min, int n, int start){
        if (n == 0){
            ans.push_back(int2time(hour, min));
        }
        for (int i = start; i < 10 && n > 0; i++){
            if (i < 4){
                if (hour + pow(2, i) < 12) readBinaryWatchHelper(ans, hour + pow(2, i), min, n-1, i+1);
            } else {
                if (min + pow(2, i-4) < 60) readBinaryWatchHelper(ans, hour, min + pow(2, i-4), n-1, i+1);
            }
        }
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> ans;
        readBinaryWatchHelper(ans, 0, 0, num, 0);
        return ans;
    }
};
