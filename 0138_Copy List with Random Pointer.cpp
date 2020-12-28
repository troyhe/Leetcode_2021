/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        // < oldNode, newNode>
        unordered_map<Node*, Node*> dic;
        Node* dummy = new Node(0);
        Node* cur = dummy;
        while (head){
            if (dic.find(head) == dic.end()){
                Node* copy = new Node(head->val);
                dic[head] = copy;
            }
            cur->next = dic[head];
            cur = cur->next;
            if (head->random){
                if (dic.find(head->random) == dic.end()){
                    Node* copy = new Node(head->random->val);
                    dic[head->random] = copy;
                }
                cur->random = dic[head->random];
            } else {
                cur->random = nullptr;
            }
            head = head->next;
            // cur = cur->next;
        }
        return dummy->next;
    }
};
