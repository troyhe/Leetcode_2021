class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // <number, idx> 
        unordered_map<int, int> table;
        vector<int> ans(2, 0);
        for (int i = 0; i < nums.size(); i++){
            if (table.find(target - nums[i]) != table.end()){
                ans[0] = table[target - nums[i]];
                ans[1] = i;
                return ans;
            }
            table[nums[i]] = i;
        }
        return ans;
    }
};
