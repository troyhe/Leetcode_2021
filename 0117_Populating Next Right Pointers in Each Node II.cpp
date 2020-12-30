/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        // There will be at least two loops
        // One to tranverse a level
        // One to tranverse all the levels
        Node* levelHead = root;
        Node* nextLevelHead;
        while (levelHead){
            Node* cur = levelHead;
            Node* prev = nullptr;
            //bool setNextLevel = false;
            while (cur){
                if (cur->left){
                    if (prev) prev->next = cur->left;
                    else nextLevelHead = cur->left;
                    prev = cur->left;
                }
                if (cur->right){
                    if (prev) prev->next = cur->right;
                    else nextLevelHead = cur->right;
                    prev = cur->right;
                }
                cur = cur->next;
            }
            levelHead = nextLevelHead;
            nextLevelHead = nullptr;
        }
        return root;
    }
};
