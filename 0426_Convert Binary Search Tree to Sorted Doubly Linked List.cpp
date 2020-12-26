/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
    // return
//     Node* treeToDoublyListHelper(Node* root){
        
//     }
    Node* append(Node* first, Node* second){
        Node* second_tail = second->left;
        first->left->right = second;
        second->left = first->left;
        first->left = second_tail;
        second_tail->right = first;
        return first;
    }
public:
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        Node* left = treeToDoublyList(root->left);
        Node* right = treeToDoublyList(root->right);
        root->left = root->right = root;
        if (left) root = append(left, root);
        if (right) root = append(root, right);
        return root;
    }
};
