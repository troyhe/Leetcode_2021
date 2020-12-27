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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        for (int i = 0; i < k; i++){
            if (first->next) first = first->next;
            else return dummy->next;
        }
        ListNode* end = first;
        ListNode* rest = reverseKGroup(end->next, k);
        // Reverse Part;
        ListNode* tail = dummy->next;
        ListNode* reverse = tail->next;
        tail->next = rest;
        ListNode* temp;
        for (int i = 0; i < k - 1; i++){
            temp = reverse;
            reverse = reverse->next;
            temp->next = dummy->next;
            dummy->next = temp;
        }
        return dummy->next;
        
    }
};
