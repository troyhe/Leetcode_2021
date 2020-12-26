class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if (nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 3; i++){
            if (i != 0 && nums[i] == nums[i-1]) continue;
            for (int j = i + 1; j < nums.size() - 2; j++){
                if (j != i + 1 && nums[j] == nums[j-1]) continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target){
                        vector<int> candidate(4);
                        candidate[0] = nums[i];
                        candidate[1] = nums[j];
                        candidate[2] = nums[left++];
                        candidate[3] = nums[right--];
                        ans.push_back(candidate);
                        while (left < right && nums[left] == nums[left-1]) left++;
                    } else if (sum < target){
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
