class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = nums.size() - 1;
        for (p1 = 0; p1 < nums.size(); p1++){
            if (nums[p1] != 0) break;
        }
        for (int i = p1; i <= p2;){
            if (nums[i] == 0){
               swap(nums[p1++], nums[i++]); 
            } else if (nums[i] == 2){
                swap(nums[p2--], nums[i]);
            } else {
                i++;
            }
        }
    }
};
