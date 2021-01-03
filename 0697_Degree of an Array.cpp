class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_map<int, int> counter;
        int maxVal = 0;
        for (int i = 0; i < nums.size(); i++){
            if (left.find(nums[i]) == left.end()) left[nums[i]] = i;
            right[nums[i]] = i;
            counter[nums[i]]++;
            maxVal = max(maxVal, counter[nums[i]]);
        }
        // int maxIdx; 
        int ans = nums.size();
        for (auto it: counter){
            if (it.second == maxVal){
                int idx = it.first;
                ans = min(ans, right[idx] - left[idx] + 1);    
            }
        }
        return ans;
    }
};
