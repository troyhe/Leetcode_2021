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
    int longestPath;
    int univalSubtree(TreeNode* root){
        if (!root) return 0;
        int left = univalSubtree(root->left);
        int right = univalSubtree(root->right);
        if (!root->left || root->left->val != root->val) left = 0;
        if (!root->right || root->right->val != root->val) right = 0;
        int path = 1 + left + right;
        longestPath = max(longestPath, path);
        return max(left, right) + 1;
    }
public:
    int longestUnivaluePath(TreeNode* root) {
        longestPath = 0;
        if (!root) return 0;
        univalSubtree(root);
        return longestPath - 1;
    }
};
