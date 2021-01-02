/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* parent;
    TreeNode* inorderSuccessorHelper(TreeNode* root, TreeNode* p){
        if (!root) return nullptr;
        if (root == p) return parent;
        if (root->val < p->val) return inorderSuccessorHelper(root->right, p);
        parent = root;
        return inorderSuccessorHelper(root->left, p);
    }
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!p) return nullptr;
        if (p->right){
            TreeNode* successor = p->right;
            while (successor->left){
                successor = successor->left;
            }
            return successor;
        }
        return inorderSuccessorHelper(root, p);

        
    }
};
