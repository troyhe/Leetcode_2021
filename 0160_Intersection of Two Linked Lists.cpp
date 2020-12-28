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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        ListNode* tempA = headA;
        int lengthA = 1;
        while (tempA->next){
            lengthA += 1;
            tempA = tempA->next;
        }
        int lengthB = 1;
        ListNode* tempB = headB;
        while (tempB->next){
            lengthB += 1;
            tempB = tempB->next;   
        }
        if (tempA != tempB) return nullptr;
        if (lengthA > lengthB){
            for (int i = 0; i < lengthA - lengthB; i++){
                headA = headA->next;
            }
        } else {
            for (int i = 0; i < lengthB - lengthA; i++){
                headB = headB->next;
            }
        }
        while (headA != headB){
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
