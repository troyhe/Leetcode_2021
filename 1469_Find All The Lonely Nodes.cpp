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
    void getLonelyNodesHelper(vector<int>& ans, TreeNode* root){
        if (!root) return;
        getLonelyNodesHelper(ans, root->left);
        getLonelyNodesHelper(ans, root->right);
        if (root->left && !root->right) ans.push_back(root->left->val);
        else if (!root->left && root->right) ans.push_back(root->right->val);
    }
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        getLonelyNodesHelper(ans, root);
        return ans;
    }
};
