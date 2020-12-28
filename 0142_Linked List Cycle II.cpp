/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head) return nullptr;
        ListNode* firstPtr = head; // Fast one
        ListNode* secondPtr = head; // Slow one
        bool cycle = false;
        while (firstPtr->next && firstPtr->next->next){
            firstPtr = firstPtr->next->next;
            secondPtr = secondPtr->next;
            if (firstPtr == secondPtr){
                cycle = true;
                break;
            }
        }
        if (!cycle) return nullptr;
        // Use equation to solve the problem;
        while (head != firstPtr){
            head = head->next;
            firstPtr = firstPtr->next;
        }
        return head;
    }
};
