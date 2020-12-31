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
    void sumNumbersHelper(TreeNode* root, int cur){
        // root cannot be nullptr
        cur = cur * 10 + root->val;
        if (!root->left && !root->right) sum += cur;
        if (root->left) sumNumbersHelper(root->left, cur);
        if (root->right) sumNumbersHelper(root->right, cur);
    }
public:
    int sumNumbers(TreeNode* root) {
        sum = 0;
        if (!root) return 0;
        sumNumbersHelper(root, 0);
        return sum;
    }
};
