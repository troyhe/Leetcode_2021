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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        //if (m == n) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (int i = 0; i < m - 1; i++){
            prev = prev->next;
        }
        ListNode* firstReverseNode = prev->next;
        ListNode* temp = firstReverseNode->next;
        firstReverseNode->next = nullptr;
        ListNode* record;
        for (int i = 0; i < n - m; i++){
            record = prev->next;
            prev->next = temp;
            temp = temp->next;
            prev->next->next = record;
        }
        firstReverseNode->next = temp;
        return dummy->next;
    }
};
