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
    int longest;
    int longestConsecutiveHelper(TreeNode* root){
        // Return the longest tree ending at root
        if (!root) return 0;
        int length = 1;
        int left = longestConsecutiveHelper(root->left);
        int right = longestConsecutiveHelper(root->right);
        if (root->left && root->val + 1 == root->left->val){
            length = 1 + left;
        }
        if (root->right && root->val + 1 == root->right->val){
            length = max(length, 1 + right);
        }
        longest = max(longest, length);
        return length;
    }
public:
    int longestConsecutive(TreeNode* root) {
        longest = 0;
        longestConsecutiveHelper(root);
        return longest;
    }
};
