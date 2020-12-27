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
    ListNode* deleteNodes(ListNode* head, int m, int n) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = dummy;
        for (int i = 0; i < m; i++){
            if (first->next) first = first->next;
            else return head;
        }
        ListNode* second = first;
        for (int i = 0; i < n; i++){
            if (second->next) second = second->next;
            else break;
        }
        first->next = deleteNodes(second->next, m, n);
        return dummy->next;
    }
};
