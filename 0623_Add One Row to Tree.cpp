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
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (!root) return nullptr;
        if (d == 1){
            TreeNode* left = new TreeNode(v, root, nullptr);
            return left;
        }
        if (d > 2){
            root->left = addOneRow(root->left, v, d - 1);
            root->right = addOneRow(root->right, v, d - 1);
            return root;
        }
        TreeNode* left = new TreeNode(v, root->left, nullptr);
        TreeNode* right = new TreeNode(v, nullptr, root->right);
        root->left = left;
        root->right = right;
        return root;
    }
};
