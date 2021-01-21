/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> monoStack;
        vector<int> ans(nums.size(), 0);
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
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        while (head){
            nums.push_back(head->val);
            head = head->next;
        }
        return nextGreaterElements(nums);
    }
};
