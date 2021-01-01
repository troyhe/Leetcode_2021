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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> level;
        vector<int> ans;
        if (!root) return ans;
        level.push(root);
        while (!level.empty()){
            int size = level.size();
            for (int i = 0; i < size - 1; i++){
                TreeNode* cur = level.front();
                level.pop();
                if (cur->left) level.push(cur->left);
                if (cur->right) level.push(cur->right);
            }
            TreeNode* cur = level.front();
            level.pop();
            if (cur->left) level.push(cur->left);
            if (cur->right) level.push(cur->right);
            ans.push_back(cur->val);
        }
        return ans;
    }
};
