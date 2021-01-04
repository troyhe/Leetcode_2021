class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int total = 0;
        if (nums.empty()) return 0;
        queue<int> subarray;
        int product = 1;
        for (int i = 0; i < nums.size(); i++){
            while (!subarray.empty() && product * nums[i] >= k){
                int cur = subarray.front();
                subarray.pop();
                product /= cur;
            }
            if (product * nums[i] >= k){
                continue;
            } else {
                subarray.push(nums[i]);
                product *= nums[i];
                total += subarray.size();
            }
        }
        return total;
    }
};
