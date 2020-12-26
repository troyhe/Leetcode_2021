class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() <= 2) return ans;
            
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            int target = - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right){
                if (nums[left] + nums[right] == target){
                    vector<int> triplet(3);
                    triplet[0] = nums[i];
                    triplet[1] = nums[left++];
                    triplet[2] = nums[right--];
                    ans.push_back(triplet);
                    // update one side is enough to remove duplicate
                    while (left < right && nums[left] == nums[left-1]) left++;
                } else if (nums[left] + nums[right] < target){
                    left ++;
                } else {
                    right --;
                }
            }
        }
        
        return ans;
    }
};
