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
    ListNode* partition(ListNode* head, int x) {
        ListNode* dummyS = new ListNode(0);
        ListNode* tempS = dummyS;
        ListNode* dummyG = new ListNode(0);
        ListNode* tempG = dummyG;
        while (head){
            if (head->val < x){
                tempS->next = head;
                head = head->next;
                tempS->next->next = nullptr;
                tempS = tempS->next;
                
            } else {
                tempG->next = head;
                head = head->next;
                tempG->next->next = nullptr;
                tempG = tempG->next;
            }
        }
        tempS->next = dummyG->next;
        return dummyS->next;
    }
};
