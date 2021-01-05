class Solution {
    string rangeHelper(int lower, int upper){
        return (lower == upper)?to_string(lower):to_string(lower)+"->"+to_string(upper);
    }
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        if (nums.empty()){
            ans.push_back(rangeHelper(lower, upper));
            return ans;
        }
        if (nums[0] != lower){
            ans.push_back(rangeHelper(lower, nums[0]-1));
        }
        for (int i = 1; i < nums.size(); i++){
            if (nums[i]-1 != nums[i-1]){
                ans.push_back(rangeHelper(nums[i-1]+1,nums[i]-1));
            }
        }
        if (nums[nums.size()-1] != upper){
            ans.push_back(rangeHelper(nums[nums.size()-1]+1, upper));
        }
        return ans;
    }
};
