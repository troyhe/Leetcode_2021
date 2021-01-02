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
    void binaryTreePaths(vector<string> &ans, string cur, TreeNode* root){
        if (!root) return;
        if (!root->left && !root->right){
            cur = cur + to_string(root->val);
            ans.push_back(cur);
            return;
        }
        cur = cur + to_string(root->val) + "->";
        binaryTreePaths(ans, cur, root->left);
        binaryTreePaths(ans, cur, root->right);
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        binaryTreePaths(ans, "", root);
        return ans;
    }
};
