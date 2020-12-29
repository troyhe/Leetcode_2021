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
    // Inorder tranverse the tree so that we can get a sorted array
    vector<int> ans;
    int last;
    int count;
    int maxCount;
    void findModeHelper(TreeNode* root){
        if (!root) return;
        findModeHelper(root->left);
        if (root->val == last){
            count ++;
        } else {
            last = root->val;
            count = 1;
        }
        if (count > maxCount){
            ans = vector<int>(1, root->val);
            maxCount = count;
        } else if (count == maxCount){
            ans.push_back(root->val);
        }
        findModeHelper(root->right);
    }
public:
    vector<int> findMode(TreeNode* root) {
        //vector<int> ans;
        count = 0;
        maxCount = 0;
        last = INT_MIN;
        findModeHelper(root);
        return ans;
    }
};
