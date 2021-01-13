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
    int countNode(ListNode* head){
        int count = 0;
        while (head){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* nextStart;
    ListNode* nextToAppend;
    
    ListNode* split(ListNode* head, int size){
        int i = 0;
        while (head && i < size - 1){
            head = head->next;
            i++;
        }
        if (!head || !head->next){
            nextStart = nullptr;
            return nullptr;
        }
        ListNode* mid = head->next;
        head->next = nullptr;
        ListNode* tail = mid;
        i = 0;
        while (tail && i < size - 1){
            tail = tail->next;
            i++;
        }
        nextStart = tail?tail->next:nullptr;
        if (tail) tail->next = nullptr;
        return mid;
    }
    
    void merge(ListNode* list1, ListNode* list2){
        ListNode* head = new ListNode(0);
        ListNode* dummy = head;
        while (list1 && list2){
            if (list1->val <= list2->val){
                head->next = list1;
                head = head->next;
                list1 = list1->next;
            } else {
                head->next = list2;
                head = head->next;
                list2 = list2->next;
            }
        }
        head->next = list1?list1:list2;
        while (head->next){
            head = head->next;
        }
        nextToAppend->next = dummy->next;
        nextToAppend = head;
    }
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        int n = countNode(head);
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        for (int size = 1; size <= n; size *= 2){
            ListNode* start = dummy->next;
            dummy->next = nullptr;
            nextToAppend = dummy;
            while (start){
                ListNode* mid = split(start, size);
                merge(start, mid);
                start = nextStart; 
            }
            
        }
        return dummy->next;
    }
};
