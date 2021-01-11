class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        // sort(intervals.begin(), intervals.end());
        // priority_queue<int, vector<int>, greater<int>> pq;
        // int minRoom = 0;
        // for (vector<int> &vec: intervals){
        //     if (pq.empty() || pq.top() > vec[0]){
        //         pq.push(vec[1]);
        //     } else {
        //         pq.pop();
        //         pq.push(vec[1]);
        //     }
        // }
        // return pq.size();
        vector<int> begin(intervals.size(), 0);
        vector<int> end(intervals.size(), 0);
        for (int i = 0; i < intervals.size(); i++){
            begin[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }
        sort(begin.begin(), begin.end());
        sort(end.begin(), end.end());
        int beginIdx = 0;
        int endIdx = 0;
        int minRoom = 0;
        while (beginIdx < intervals.size()){
            if (begin[beginIdx] < end[endIdx]){
                beginIdx++;
                minRoom = max(minRoom, beginIdx - endIdx);
            } else {
                endIdx++;
            }
        }
        return minRoom;
    }
};
