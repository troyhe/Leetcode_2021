class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        // < partial sum for [i, n], n>
        unordered_map<int, int> dic;
        int maxLength = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if (sum == k) maxLength = max(maxLength, i+1);
            if (dic.find(sum) == dic.end()) dic[sum] = i;
            if (dic.find(sum - k) != dic.end()){
                maxLength = max(maxLength, i - dic[sum-k]);
            }
        }
        return maxLength;
    }
};
