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
    TreeNode* sortedArrayToBSTHelper(vector<int>& nums, int beginIdx, int endIdx) {
        // [beginIdx, endIdx)
        if (beginIdx >= endIdx) return nullptr;
        int mid = (beginIdx + endIdx)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, beginIdx, mid);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, endIdx);
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size());
    }
};
