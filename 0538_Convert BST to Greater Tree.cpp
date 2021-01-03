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
    int sum;
    void convertBSTHelper(TreeNode* root){
        if (!root) return;
        convertBSTHelper(root->right);
        sum += root->val;
        root->val = sum;
        convertBSTHelper(root->left);
    }
public:
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        convertBSTHelper(root);
        return root;
    }
};
