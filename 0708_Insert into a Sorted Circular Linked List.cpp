/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if (!head){
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        Node* insertNode = new Node(insertVal);
        Node* temp = head;
        bool equal = false;
        while (true){
            if (temp->next->val >= temp->val){
                if (insertVal <= temp->next->val && insertVal >= temp->val){
                    insertNode->next = temp->next;
                    temp->next = insertNode;
                    break;
                }
            } else {
                if (insertVal <= temp->next->val || insertVal >= temp->val){
                    insertNode->next = temp->next;
                    temp->next = insertNode;
                    break;
                }
            }
            temp = temp->next;
            if (temp == head){
                temp = head->next;
                head->next = insertNode;
                insertNode->next = temp;
                break;
            }
        }
        return head;
    }
};
