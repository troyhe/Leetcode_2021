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
    int count;
    int univalSubtree(TreeNode* root){
        if (!root) return INT_MAX;
        int left = univalSubtree(root->left);
        int right = univalSubtree(root->right);
        if (left != INT_MAX && left != root->val) return INT_MIN;
        if (right != INT_MAX && right != root->val) return INT_MIN;
        count += 1;
        return root->val;
    }
public:
    int countUnivalSubtrees(TreeNode* root) {
        count = 0;
        univalSubtree(root);
        return count;
    }
};
