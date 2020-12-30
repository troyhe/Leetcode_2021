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
    void pathSumHelper(vector<vector<int>>& ans, vector<int>& cur, TreeNode* root, int sum){
        if (!root) return;
        if (!root->left && !root->right){
            if (root->val == sum){
                cur.push_back(root->val);
                ans.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(root->val);
        pathSumHelper(ans, cur, root->left, sum - root->val);
        pathSumHelper(ans, cur, root->right, sum - root->val);
        cur.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur;
        pathSumHelper(ans, cur, root, sum);
        return ans;
    }
};
