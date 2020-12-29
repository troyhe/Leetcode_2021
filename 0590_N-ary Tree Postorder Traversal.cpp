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
    void postorderHelper(vector<int>& ans, Node* root){
        if (!root) return;
        for (Node* child: root->children){
            postorderHelper(ans, child);
        }
        ans.push_back(root->val);
    }
        
public:
    vector<int> postorder(Node* root) {
        vector<int> ans;
        postorderHelper(ans, root);
        return ans;
    }
};
