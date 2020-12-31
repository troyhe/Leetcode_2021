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
    int maxPath;
    int maxPathHelper(TreeNode* root){
        // Return the max sum of path end at the node
        if (!root) return 0;
        int val = root->val;
        int left = maxPathHelper(root->left);
        int right = maxPathHelper(root->right);
        int maxVal = max(0, left) + val + max(0, right);
        maxPath = max(maxPath, maxVal);
        return val + max(0, max(left, right));
    }
public:
    int maxPathSum(TreeNode* root) {
        maxPath = INT_MIN;
        if (!root) return 0;
        maxPathHelper(root);
        return maxPath;
    }
};
