class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int total = 0;
        int sum = 0;
        // <sumOfArray, number>
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum == k) total += 1;
            total += count[sum - k];
            count[sum]++;
        }
        return total;
    }
};
