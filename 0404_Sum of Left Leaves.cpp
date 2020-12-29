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
    void sumOfLeftLeavesHelper(TreeNode* root){
        if (!root) return;
        sumOfLeftLeavesHelper(root->right);
        if (root->left && !root->left->left && !root->left->right){
            sum += root->left->val;
        } else {
            sumOfLeftLeavesHelper(root->left);
        }
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        sum = 0;
        sumOfLeftLeavesHelper(root);
        return sum;
    }
};
