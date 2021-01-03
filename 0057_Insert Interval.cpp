class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int idx = 0;
        for (idx = 0; idx < intervals.size(); idx++){
            if (intervals[idx][1] < newInterval[0]){
                ans.push_back(intervals[idx]);
            } else {
                break;
            }
        }
        for (; idx < intervals.size(); idx++){
            if (intervals[idx][0] <= newInterval[1]){
                newInterval[0] = min(intervals[idx][0], newInterval[0]);
                newInterval[1] = max(intervals[idx][1], newInterval[1]);
            } else {
                break;
            }
        }
        ans.push_back(newInterval);
        for (; idx < intervals.size(); idx++){
            ans.push_back(intervals[idx]);
        }
        return ans;
    }
};
