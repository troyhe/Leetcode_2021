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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) return ans;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()){
            int size = level.size();
            int large = INT_MIN;
            for (int i = 0; i < size; i++){
                TreeNode* cur = level.front();
                level.pop();
                large = max(large, cur->val);
                if (cur->left) level.push(cur->left);
                if (cur->right) level.push(cur->right);
            }
            ans.push_back(large);
        }
        return ans;
    }
};
