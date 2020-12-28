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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0);
        // int last
        bool repeat = false;
        ListNode* cur = dummy;
        while (head->next){
            if (head->val != head->next->val && !repeat){
                cur->next = head;
                cur = cur->next;
                head = head->next;
            } else if (head->val != head->next->val && repeat){
                head = head->next;
                repeat = false;
            } else if (head->val == head->next->val){
                repeat = true;
                head = head->next;
            }
        }
        if (repeat) cur->next = nullptr;
        else cur->next = head;
        return dummy->next;
    }
};
