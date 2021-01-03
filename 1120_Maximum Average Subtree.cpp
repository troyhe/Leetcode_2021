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
    double maxAverage;
    vector<int> helper(TreeNode* root){
        // return [num, sum]
        vector<int> ans(2,0);
        if (!root) return ans;
        vector<int> left = helper(root->left);
        vector<int> right = helper(root->right);
        ans[0] = 1 + left[0] + right[0];
        ans[1] = root->val + left[1] + right[1];
        maxAverage = max(maxAverage, ans[1]/(double)ans[0]);
        return ans;
    }
public:
    double maximumAverageSubtree(TreeNode* root) {
        maxAverage = INT_MIN;
        helper(root);
        return maxAverage;
    }
};
