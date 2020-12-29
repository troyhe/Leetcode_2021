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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<TreeNode*> level;
        level.push(root);
        bool order = true;
        while (!level.empty()){
            int size = level.size();
            TreeNode* cur;
            vector<int> temp;
            for (int i = 0; i < size; i++){
                cur = level.front();
                level.pop();
                temp.push_back(cur->val);
                if (cur->left) level.push(cur->left);
                if (cur->right) level.push(cur->right);
            }
            if (!order) reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            order = !order;
        }
        return ans;
    }
};
