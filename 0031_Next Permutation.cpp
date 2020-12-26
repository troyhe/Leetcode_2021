class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // find the first element that nums[i] < nums[i+1] from the back
        int i = nums.size() - 2;
        if (i < 0) return;
        for (; i >= 0; i--){
            if (nums[i] < nums[i+1]) break;
        }
        if (i >= 0){
            // find the element that nums[j] > nums[i] from the back and swap that
            int j = nums.size() - 1;
            for (; j > i; j--){
                if (nums[i] < nums[j]) break;
            }
            swap(nums[i], nums[j]);
        }
        // reverse nums[i:]
        for (int j = 1; i + j < nums.size() - j; j++){
            swap(nums[i+j], nums[nums.size() - j]);
        }
        
    }
};
