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
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode* firstPtr = head; // Fast one
        ListNode* secondPtr = head; // Slow one
        while (firstPtr->next && firstPtr->next->next){
            firstPtr = firstPtr->next->next;
            secondPtr = secondPtr->next;
            if (firstPtr == secondPtr) return true;
        }
        return false;
    }
};
