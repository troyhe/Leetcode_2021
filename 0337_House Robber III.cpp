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
    vector<int> robHelper(TreeNode* root){
        // [rob the root, do not rob the root]
        vector<int> ans = {0,0};
        if (!root) return ans;
        vector<int> left = robHelper(root->left);
        vector<int> right = robHelper(root->right);
        ans[0] = root->val + left[1] + right[1];
        ans[1] = max(left[0], left[1]) + max(right[0], right[1]);
        return ans;
    }
public:
    int rob(TreeNode* root) {
        vector<int> ans = robHelper(root);
        return max(ans[0], ans[1]);
    }
};
