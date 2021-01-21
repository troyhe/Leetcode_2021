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
    TreeNode* first1;
    TreeNode* first2;
    TreeNode* second1;
    TreeNode* second2;
    TreeNode* last;
    void inorder(TreeNode* root){
        if (!root) return;
        inorder(root->left);
        if (last && last->val > root->val){
            if (first1){
                second1 = last;
                second2 = root;
            } else {
                first1 = last;
                first2 = root;
            }
        }
        last = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        last = first1 = first2 = second1 = second2 = nullptr;
        inorder(root);
        if (second1){
            swap(first1->val, second2->val);
        } else {
            swap(first1->val, first2->val);
        }
    }
};
