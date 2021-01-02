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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* last = nullptr; // To check whether the top of the stack has been visited
        
        while (root || !s.empty()){
            while (root){
                s.push(root);
                root = root->left;
            }
            TreeNode* cur = s.top();
            if (cur->right && last != cur->right){
                root = cur->right;
            } else {
                s.pop();
                ans.push_back(cur->val);
                last = cur;
            }
        }
        return ans;
    }
};
