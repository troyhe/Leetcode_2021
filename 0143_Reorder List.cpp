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
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        // Cut the list into two
        
        ListNode* first = head;
        ListNode* second = head;
        while (first->next && first->next->next){
            first = first->next->next;
            second = second->next;
        }
        ListNode* list2 = second->next;
        second->next = nullptr;
        
        // Reverse for second list
        ListNode* dummy = new ListNode(0, list2);
        ListNode* temp;
        list2 = list2->next;
        dummy->next->next = nullptr;
        while (list2){
            temp = dummy->next;
            dummy->next = list2;
            list2 = list2->next;
            dummy->next->next = temp;
        }
        ListNode* evenHead = dummy->next;
        ListNode* oddHead = head;
        
        // Merge them
        dummy = new ListNode(0);
        temp = dummy;
        while (evenHead){
            temp->next = oddHead;
            oddHead = oddHead->next;
            temp->next->next = evenHead;
            evenHead = evenHead->next;
            temp = temp->next->next;
        }
        if (oddHead) temp->next = oddHead;
        else temp->next = nullptr;
        // return dummy->next;
        
    }
};
