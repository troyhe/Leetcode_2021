class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monoStack;
        vector<int> ans(nums.size(), -1);
        for (int i = 0; i < nums.size(); i++){
            while (!monoStack.empty() && nums[monoStack.top()] < nums[i]){
                int cur = monoStack.top();
                monoStack.pop();
                ans[cur] = nums[i];
            }
            monoStack.push(i);
        }
        for (int i = 0; i < nums.size(); i++){
            while (!monoStack.empty() && nums[monoStack.top()] < nums[i]){
                int cur = monoStack.top();
                monoStack.pop();
                ans[cur] = nums[i];
            }
            monoStack.push(i);
        }
        return ans;
    }
};
