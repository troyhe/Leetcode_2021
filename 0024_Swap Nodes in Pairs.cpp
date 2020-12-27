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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        head = dummy;
        ListNode* temp;
        while (head->next && head->next->next){
            temp = head->next;
            head->next = temp->next;
            temp->next= head->next->next;
            head->next->next = temp;
            head = head->next->next;
        }
        
        return dummy->next;
    }
};
