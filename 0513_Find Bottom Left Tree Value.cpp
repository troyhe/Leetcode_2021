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
    int findBottomLeftValue(TreeNode* root) {
        int val;
        queue<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            int size = s.size();
            for (int i = 0; i < size; i++){
                TreeNode* cur = s.front();
                s.pop();
                if (i == 0) val = cur->val;
                if (cur->left) s.push(cur->left);
                if (cur->right) s.push(cur->right);
            }
        }
        return val;
    }
};
