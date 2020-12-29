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
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> level;
        if (!root) return ans;
        level.push(root);
        
        while (!level.empty()){
            int n = level.size();
            vector<int> temp(n, 0);
            TreeNode* node;
            for (int i = 0; i < n; i++){
                node = level.front();
                level.pop();
                temp[i] = node->val;
                if (node->left) level.push(node->left);
                if (node->right) level.push(node->right);
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
