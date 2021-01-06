class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++){
            if (dic.find(nums[i]) == dic.end()) dic[nums[i]] = i;
            else {
                if (i - dic[nums[i]] <= k) return true;
                else dic[nums[i]] = i;
            }
        }
        return false;
    }
};
