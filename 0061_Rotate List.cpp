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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int n = 1;
        ListNode* temp = head;
        while (temp->next){
            temp = temp->next;
            n++;
        }
        ListNode* tail = temp;
        k = k % n;
        if (k == 0) return head;
        ListNode* newHead;
        ListNode* newTail = head;
        for (int i = 0; i < n - k - 1; i++){
            newTail = newTail->next;
        }
        newHead = newTail->next;
        newTail->next = nullptr;
        tail->next = head;
        return newHead;
    }
};
