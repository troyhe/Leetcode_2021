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
    TreeNode* buildTreeHelper(vector<int>& inorder, vector<int>& postorder, int inorderLeft, int inorderRight, int postorderLeft, int postorderRight) {
        if (inorderLeft > inorderRight) return nullptr;
        if (inorderLeft == inorderRight) return new TreeNode(inorder[inorderLeft]);
        int rootIdx = inorderLeft;
        for (;rootIdx <= inorderRight; rootIdx++){
            if (postorder[postorderRight] == inorder[rootIdx]) break;
        }
        TreeNode* root = new TreeNode(postorder[postorderRight]);
        root->left = buildTreeHelper(inorder, postorder, inorderLeft, rootIdx-1, postorderLeft, postorderRight - inorderRight + rootIdx - 1);
        root->right =  buildTreeHelper(inorder, postorder, rootIdx+1, inorderRight, postorderRight - inorderRight + rootIdx, postorderRight - 1);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return nullptr;
        return buildTreeHelper(inorder, postorder, 0, inorder.size()-1, 0, inorder.size()-1);
    }
};
