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
    int numComponents(ListNode* head, vector<int>& G) {
        unordered_set<int> dic;
        for (int i: G){
            dic.insert(i);
        }
        int count = 0;
        bool last = false;
        while (head){
            if (dic.find(head->val) != dic.end()){
                last = true;
            } else {
                if (last) count++;
                last = false;
            }
            head = head->next;
        }
        if (last) count++;
        return count;
    }
};
