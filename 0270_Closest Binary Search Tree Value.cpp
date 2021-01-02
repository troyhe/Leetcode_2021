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
    long small;
    void findSmall(TreeNode* root, double target){
        if (!root) return;
        if (root->val <= target && root->val > small) small = root->val;
        if (root->val == target) return;
        if (root->val > target) findSmall(root->left, target);
        else findSmall(root->right, target);
    }
    long large;
    void findLarge(TreeNode* root, double target){
        if (!root) return;
        if (root->val>= target && root->val < large) large = root->val;
        if (root->val == target) return;
        if (root->val < target) findLarge(root->right, target);
        else findLarge(root->left, target);
    }
public:
    int closestValue(TreeNode* root, double target) {
        // find the largest value smaller than target
        small = LONG_MIN;
        findSmall(root, target);
        large = LONG_MAX;
        findLarge(root, target);
        if (small == LONG_MIN) return large;
        if (large == LONG_MAX) return small;
        if (large - target < target - small) return large;
        return small;
    }
};
