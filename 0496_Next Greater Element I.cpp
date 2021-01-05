class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> monoStack;
        unordered_map<int, int> dic;
        for (int num: nums2){
            while (!monoStack.empty() && monoStack.top() < num){
                dic[monoStack.top()] = num;
                monoStack.pop();
            }
            monoStack.push(num);
        }
        vector<int> ans(nums1.size(), -1);
        for (int i = 0; i < nums1.size(); i++){
            if (dic.find(nums1[i]) != dic.end()) ans[i] = dic[nums1[i]];
        }
        return ans;
    }
};
