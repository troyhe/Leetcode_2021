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
    // if we want to find the least element at the top, use greater than
    class ListNodeGreater{
        public:
        bool operator()(const ListNode* l1, const ListNode* l2){
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* head = dummy;
        priority_queue<ListNode*, vector<ListNode*>, ListNodeGreater> pq;
        for (ListNode* l: lists) if (l) pq.push(l);
        while (!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();
            if (smallest->next) pq.push(smallest->next);
            head->next = smallest;
            head = head->next;
        }
        return dummy->next;
    }
};
