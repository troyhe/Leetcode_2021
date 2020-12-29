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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        if (!root) return ans;
        queue<TreeNode*> level;
        level.push(root);
        while (!level.empty()){
            int size = level.size();
            TreeNode* cur;
            double sum = 0;
            //int count = 0;
            for (int i = 0; i < size; i++){
                cur = level.front();
                level.pop();
                sum += cur->val;
                if (cur->left) level.push(cur->left);
                if (cur->right) level.push(cur->right);
            }
            ans.push_back(sum/size);
        }
        return ans;
    }
};
