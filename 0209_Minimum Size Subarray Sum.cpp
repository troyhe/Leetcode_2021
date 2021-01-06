class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int minlength = nums.size() + 1;
        int sum = 0;
        int left = 0;
        int right = 0;
        for (; right < nums.size(); right++){
            sum += nums[right];
            while (left <= right && sum >= s){
                minlength = min(minlength, right - left + 1);
                sum -= nums[left++];
            }
        }
        return (minlength == nums.size()+1)?0:minlength;
    }
};
