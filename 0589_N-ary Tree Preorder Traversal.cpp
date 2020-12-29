/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    void preorderHelper(vector<int>& ans, Node* root){
        if (!root) return;
        ans.push_back(root->val);
        for (Node* child: root->children){
            preorderHelper(ans, child);
        }
    }
public:
    vector<int> preorder(Node* root) {
        vector<int> ans;
        preorderHelper(ans, root);
        return ans;
    }
};
