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
    // For a BST, inorder traverse it -> sorted array
    int count;
    int target;
    void kthSmallestHelper(TreeNode* root){
        if (!root) return;
        if (count <= 0) return;
        kthSmallestHelper(root->left);
        if (count != 1) count--;
        else {
            target = root->val;
            count --;
        }
        kthSmallestHelper(root->right);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        count = k;
        target = INT_MIN; // an exception
        kthSmallestHelper(root);
        return target;
    }
};
