class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        // The length of the new array
        int n = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]){
                nums[n++] = nums[i];
            }
        }
        return n;
    }
};
