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
    TreeNode* constructFromPrePostHelper(vector<int>& pre, vector<int>& post, int preBegin, int preEnd, int postBegin, int postEnd){
        if (preBegin > preEnd) return nullptr;
        if (preBegin ==  preEnd) return new TreeNode(pre[preBegin]);
        int mid = postBegin;
        for (;mid <= postEnd; mid++){
            if (pre[preBegin + 1] == post[mid]) break;
        }
        TreeNode* root = new TreeNode(pre[preBegin]);
        root->left = constructFromPrePostHelper(pre, post, preBegin + 1, preBegin + mid - postBegin + 1, postBegin, mid);
        root->right = constructFromPrePostHelper(pre, post, preBegin + mid - postBegin + 2, preEnd, mid + 1, postEnd - 1);
        return root;
    } 
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        if (pre.size() == 0) return nullptr;
        return constructFromPrePostHelper(pre, post, 0, pre.size() - 1, 0, pre.size() - 1);
    }
};
