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
    bool balance;
    int isBalancedHelper(TreeNode* root){
        // Return the height of the tree
        if (!root) return 0;
        int left = isBalancedHelper(root->left);
        int right = isBalancedHelper(root->right);
        if (abs(left - right) > 1) balance = false;
        return 1 + max(left, right);
    }
public:
    bool isBalanced(TreeNode* root) {
        balance = true;
        isBalancedHelper(root);
        return balance;
    }
};
