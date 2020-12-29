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
    // [begin, end]
    vector<TreeNode*> generateTreesHelper(int begin, int end){
        vector<TreeNode*> ans;
        if (begin > end){
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = begin; i <= end; i++){
            // TreeNode* root = new TreeNode(i);
            vector<TreeNode*> left = generateTreesHelper(begin, i-1);
            vector<TreeNode*> right = generateTreesHelper(i+1, end);
            for (TreeNode* l: left){
                for (TreeNode* r: right){
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*>(0);
        return generateTreesHelper(1, n);
    }
};
