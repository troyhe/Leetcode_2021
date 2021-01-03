class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Reduce the problem to Linked List Cycle
        // int firstIdx = 0;
        // int secondIdx = 0;
        // while (true){
        //     firstIdx = nums[nums[firstIdx]];
        //     secondIdx = nums[secondIdx];
        //     if (firstIdx == secondIdx){
        //         break;
        //     }
        // }
        // firstIdx = 0;
        // while (firstIdx != secondIdx){
        //     firstIdx = nums[firstIdx];
        //     secondIdx = nums[secondIdx];
        // }
        // return firstIdx;
        
        for (int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] *= -1;
            else return idx + 1;
        }
        return nums.size();
    }
};
