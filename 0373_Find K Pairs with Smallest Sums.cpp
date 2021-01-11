class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> ans;
        set<pair<int,int>> seen;
        if (nums1.empty() || nums2.empty()) return ans;
        pq.push({nums1[0]+ nums2[0], 0, 0});
        for (int i = 0; i < k && !pq.empty(); i++){
            vector<int> cur = pq.top();
            pq.pop();
            vector<int> temp = {nums1[cur[1]], nums2[cur[2]]};
            ans.push_back(temp);
            if (cur[1] < (int)nums1.size() - 1 && !seen.count({cur[1]+1, cur[2]})){
                pq.push({nums1[cur[1]+1]+ nums2[cur[2]], cur[1]+1, cur[2]});
                seen.insert({cur[1]+1, cur[2]});
            }
            if (cur[2] < (int)nums2.size() - 1 && !seen.count({cur[1], cur[2]+1})){
                pq.push({nums1[cur[1]]+ nums2[cur[2]+1], cur[1], cur[2]+1});
                seen.insert({cur[1], cur[2]+1});
            }
        }
        return ans;
    }
};
