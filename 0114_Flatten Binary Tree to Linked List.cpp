/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* flattenHelper(TreeNode* root){
        TreeNode* newRoot = root;
        if (!root->left && !root->right) return root;
        if (!root->left && root->right){
            return flattenHelper(root->right);
        }
        if (root->left && !root->right){
            root->right = root->left;
            root->left = nullptr;
            return flattenHelper(root->right);
        }
        TreeNode* connection = flattenHelper(root->left);
        TreeNode* tail = flattenHelper(root->right);
        connection->right = root->right;
        root->right = root->left;
        root->left = nullptr;
        return tail;
        
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flattenHelper(root);
    }
};
