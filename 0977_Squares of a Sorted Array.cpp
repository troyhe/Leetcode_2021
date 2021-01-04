class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int pt1 = 0;
        while (pt1 < n && nums[pt1] < 0) pt1++;
        int pt2 = pt1 - 1;
        vector<int> ans(n, 0);
        int idx = 0;
        while (pt1 < n && pt2 >= 0){
            if (nums[pt1]*nums[pt1] < nums[pt2]*nums[pt2]){
                ans[idx++] = nums[pt1]*nums[pt1];
                pt1++;
            } else {
                ans[idx++] = nums[pt2]*nums[pt2];
                pt2--;
            }
        }
        while (pt1 < n){
            ans[idx++] = nums[pt1]*nums[pt1];
            pt1++;
        }
        while (pt2 >= 0){
            ans[idx++] = nums[pt2]*nums[pt2];
            pt2--;
        }
        return ans;
    }
};
