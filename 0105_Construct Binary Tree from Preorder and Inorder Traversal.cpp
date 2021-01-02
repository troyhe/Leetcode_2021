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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int preorderLeft, int preorderRight, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) return nullptr;
        if (preorderLeft == preorderRight) return new TreeNode(preorder[preorderLeft]);
        int rootIdx = inorderLeft;
        for (;rootIdx <= inorderRight; rootIdx++){
            if (preorder[preorderLeft] == inorder[rootIdx]) break;
        }
        TreeNode* root = new TreeNode(preorder[preorderLeft]);
        root->left = buildTreeHelper(preorder, inorder, preorderLeft + 1, preorderLeft + rootIdx - inorderLeft, inorderLeft, rootIdx-1);
        root->right =  buildTreeHelper(preorder, inorder, preorderLeft + rootIdx - inorderLeft + 1, preorderRight, rootIdx+1, inorderRight);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return nullptr;
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, preorder.size() - 1);
    }
};
