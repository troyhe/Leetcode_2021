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
    TreeNode* LCA;
    int findNode(TreeNode* root, vector<TreeNode*> &nodes){
        if (!root || LCA) return 0;
        int mid = 0;
        for (TreeNode* node: nodes){
            if (node == root){
                mid = 1;
                break;
            }
        }
        int left = findNode(root->left, nodes);
        int right = findNode(root->right, nodes);
        if (left + mid + right >= nodes.size() && !LCA){
            LCA = root;
        }
        return left + right + mid;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        LCA = nullptr;
        findNode(root, nodes);
        return LCA;
    }
};
