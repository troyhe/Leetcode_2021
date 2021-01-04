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
    int minDifference;
    int last;
    bool first;
    void inorderTraverse(TreeNode* root){
        if (!root) return;
        inorderTraverse(root->left);
        if (first){
            last = root->val;
            first = false;
        } else {
            minDifference = min(minDifference, root->val - last);
            last = root->val;
        }
        inorderTraverse(root->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        first = true;
        minDifference = INT_MAX;
        inorderTraverse(root);
        return minDifference;
    }
};
