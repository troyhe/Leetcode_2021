class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.empty()) return;
        for (int i = 0; i < nums.size() - 1; i++){
            if (i % 2 == 0 && nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
            if (i % 2 == 1 && nums[i] < nums[i+1]) swap(nums[i], nums[i+1]);
        }
    }
};
