class Solution {
    string rangeHelper(int lower, int upper){
        return (lower == upper)?to_string(lower):to_string(lower)+"->"+to_string(upper);
    }
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int last = nums[0];
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]+1){
                ans.push_back(rangeHelper(last, nums[i-1]));
                last = nums[i];
            }
        }
        ans.push_back(rangeHelper(last, nums[nums.size()-1]));
        return ans;
    }
};
