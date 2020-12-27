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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode* dummy = new ListNode(0, head);
        ListNode* temp;
        head = head->next;
        dummy->next->next = nullptr;
        while (head){
            temp = dummy->next;
            dummy->next = head;
            head = head->next;
            dummy->next->next = temp;
        }
        return dummy->next;
    }
};
