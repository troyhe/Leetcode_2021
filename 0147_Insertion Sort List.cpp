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
    void insert(ListNode* list, ListNode* node){
        while (list->next && list->next->val < node->val){
            list = list->next;
        }
        node->next = list->next;
        list->next = node;
    }
public:
    ListNode* insertionSortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0, head);
        head = head->next;
        dummy->next->next = nullptr;
        while (head){
            ListNode* temp = head;
            head = head->next;
            temp->next = nullptr;
            insert(dummy, temp);
        }
        return dummy->next;
    }
};
