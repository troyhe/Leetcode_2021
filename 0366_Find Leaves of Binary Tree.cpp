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
    vector<vector<int>> ans;
    int findLeavesHelper(TreeNode* root){
        // Return the height of the tree
        if (!root) return -1;
        int left = findLeavesHelper(root->left);
        int right = findLeavesHelper(root->right);
        int height = 1 + max(left, right);
        if (ans.size() == height){
            ans.push_back({});
        }
        ans[height].push_back(root->val);
        return height;
    }
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        ans.clear();
        findLeavesHelper(root);
        return ans;
    }
};
