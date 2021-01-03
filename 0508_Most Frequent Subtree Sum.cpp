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
    int count;
    unordered_map<int, int> counter;
    vector<int> ans;
    int sumTree(TreeNode* root){
        if (!root) return 0;
        int left = sumTree(root->left);
        int right = sumTree(root->right);
        int sum = root->val + left + right;
        counter[sum]++;
        if (counter[sum] == count){
            ans.push_back(sum);
        } else if (counter[sum] > count){
            count = counter[sum];
            ans.clear();
            ans.push_back(sum);
        }
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        count = 0;
        ans.clear();
        sumTree(root);
        return ans;
    }
};
