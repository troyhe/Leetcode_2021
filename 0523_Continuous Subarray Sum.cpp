class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        //if (k == 0) return false;
        int sum = 0;
        unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++){
            if (k != 0) sum = (sum + nums[i]) % k;
            else sum += nums[i];
            if (sum == 0 && i >= 1) return true;
            if (dic.find(sum) != dic.end() && i > dic[sum] + 1) return true;
            if (dic.find(sum) == dic.end()) dic[sum] = i;
        }
        return false;
    }
};
