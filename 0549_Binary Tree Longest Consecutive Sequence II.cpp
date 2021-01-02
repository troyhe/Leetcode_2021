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
    int longest;
    vector<int> longestConsecutiveHelper(TreeNode* root){
        // Return the longest tree ending at root [increasing, decreasing]
        vector<int> ans = {0, 0};
        if (!root) return ans;
        ans[0] = ans[1] = 1;
        vector<int> left = longestConsecutiveHelper(root->left);
        vector<int> right = longestConsecutiveHelper(root->right);
        if (root->left && root->val + 1 == root->left->val){
            ans[0] = 1 + left[0];
        } else if (root->left && root->val - 1 == root->left->val){
            ans[1] = 1 + left[1];
        }
        
        if (root->right && root->val + 1 == root->right->val){
            ans[0] = max(ans[0], 1 + right[0]);
        } else if (root->right && root->val - 1 == root->right->val){
            ans[1] = max(ans[1], 1 + right[1]);
        }
        longest = max(longest, ans[0] + ans[1] - 1);
        return ans;
    }
public:
    int longestConsecutive(TreeNode* root) {
        longest = 0;
        longestConsecutiveHelper(root);
        return longest;
    }
};
