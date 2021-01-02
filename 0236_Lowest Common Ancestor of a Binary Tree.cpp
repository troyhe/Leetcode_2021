/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void findPath(TreeNode* root, TreeNode* p, deque<TreeNode*> &ans){
        // ans should be treated as a stack
        TreeNode* last = nullptr; // To check whether the top of the stack has been visited
        
        while (root || !ans.empty()){
            while (root){
                ans.push_back(root);
                root = root->left;
            }
            TreeNode* cur = ans.back();
            if (cur->right && last != cur->right){
                root = cur->right;
            } else {
                if (cur == p) return;
                ans.pop_back();
                last = cur;
            }
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        deque<TreeNode*> path_p;
        deque<TreeNode*> path_q;
        findPath(root, p, path_p);
        findPath(root, q, path_q);
        TreeNode* ancestor = nullptr;
        while (!path_p.empty() && !path_q.empty() && path_p.front() == path_q.front()){
            ancestor = path_p.front();
            path_p.pop_front();
            path_q.pop_front();
        }
        return ancestor;
    }
};
