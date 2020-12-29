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
    bool check(TreeNode* root, int index, int height){
        if (index > pow(2, height-1)) return false;
        int dividend = pow(2, height-2);
        index--;
        while (dividend > 0){
            if (index / dividend == 0){
                root = root->left;
            } else {
                root = root->right;
            }
            index = index % dividend;
            dividend /= 2;
        }
        return root != nullptr;
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        // Check the height of the tree;
        TreeNode* temp = root;
        int height = 0;
        while (temp){
            height++;
            temp = temp->left;
        }
        // If we denote height to be n
        // There will be 2^(n-1) - 1 nodes in the tree except the last level
        
        // Then we will discuss the last level (Binary Search)
        // There can be at most 2^(n-1) nodes in that level and we find the last one using binary search;
        int left = 1;
        int right = pow(2, height-1);
        while (left <= right){
            int mid = (left + right)/2;
            if (check(root, mid, height) && !check(root, mid+1, height)){
                left = mid;
                break;
            } else if (check(root, mid, height)){
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int sum = pow(2, height-1) - 1 + left;
        return sum;
    }
};
