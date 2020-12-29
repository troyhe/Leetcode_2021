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
    // Use a global variable to record the sum
    int sumTilt;
    int findTiltHelper(TreeNode* root){
        // DEFINE: Return the sum of the tree nodes
        // MODIFY: Add the tilt of the node to the sum
        if (!root) return 0;
        int left = findTiltHelper(root->left);
        int right = findTiltHelper(root->right);
        int tilt = abs(left - right);
        sumTilt += tilt;
        return left + right + root->val;
        
    }
public:
    int findTilt(TreeNode* root) {
        sumTilt = 0;
        findTiltHelper(root);
        return sumTilt;
    }
};
