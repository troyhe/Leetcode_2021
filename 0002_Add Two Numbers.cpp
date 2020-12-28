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
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) return nullptr;
        int carry = 0; // the carry bit
        ListNode* dummy = new ListNode(0); // sitinal
        ListNode* cur = dummy;
        while(l1 || l2 || carry){
            int a = (l1)?l1->val:0;
            int b = (l2)?l2->val:0;
            int sum = a + b + carry;
            if (sum >= 10){
                carry = 1;
                sum -= 10;
            } else {
                carry = 0;
            }
            cur->next = new ListNode(sum);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            cur = cur->next;
        }
        return dummy->next;
    }
};
