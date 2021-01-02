/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return nullptr;
        if (node->right){
            Node* successor = node->right;
            while (successor->left){
                successor = successor->left;
            }
            return successor;
        }
        Node* cur = node;
        while (cur->parent){
            if (cur->parent->left == cur) return cur->parent;
            cur = cur->parent;
        }
        return nullptr;
    }
};
