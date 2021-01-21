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
    int maxLength;
    int longestZigZagHelper(TreeNode* root, bool left){
        if (!root) return 0;
        
        int leftLength = 1 + longestZigZagHelper(root->left, false);
        maxLength = max(maxLength, leftLength);
        int rightLength = 1 + longestZigZagHelper(root->right, true);
        maxLength = max(maxLength, rightLength);
        if (left) return leftLength;
        else return rightLength;
    }
public:
    int longestZigZag(TreeNode* root) {
        maxLength = 0;
        longestZigZagHelper(root, true);
        longestZigZagHelper(root, false);
        return maxLength - 1;   
    }
};
