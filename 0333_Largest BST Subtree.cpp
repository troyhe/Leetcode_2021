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
    int maxBST;
    vector<int> largestBSTSubtreeHelper(TreeNode* root){
        // Return [numOfNodes, smallest value, largest value]
        vector<int> ans = {0, INT_MAX, INT_MIN};
        if (!root) return ans;
        if (!root->left && !root->right){
            ans[0] = 1;
            ans[1] = root->val;
            ans[2] = root->val;
            maxBST = max(maxBST, ans[0]);
            return ans;
        }
        vector<int> left = largestBSTSubtreeHelper(root->left);
        vector<int> right = largestBSTSubtreeHelper(root->right);
        if (left[0] == -1 || right[0] == -1){
            ans[0] = -1;
            return ans;
        }
        if (left[2] >= root->val || right[1] <= root->val){
            ans[0] = -1;
            return ans;
        }
        ans[1] = min(left[1], root->val);
        ans[2] = max(right[2], root->val);
        ans[0] = 1 + left[0] + right[0];
        maxBST = max(maxBST, ans[0]);
        return ans;
    }
public:
    int largestBSTSubtree(TreeNode* root) {
        maxBST = 0;
        largestBSTSubtreeHelper(root);
        return maxBST;
    }
};
