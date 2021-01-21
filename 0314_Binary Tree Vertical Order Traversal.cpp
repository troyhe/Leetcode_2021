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
    unordered_map<int, vector<int>> colMap;
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        colMap.clear();
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int left = 0;
        int right = 0;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                pair<TreeNode*, int> cur = q.front();
                left = min(left, cur.second);
                right = max(right, cur.second);
                q.pop();
                colMap[cur.second].push_back(cur.first->val);
                if (cur.first->left) q.push({cur.first->left, cur.second - 1});
                if (cur.first->right) q.push({cur.first->right, cur.second + 1});
            }
        }
        
        for (int i = left; i <= right; i++){
            ans.push_back(colMap[i]);
        }
        return ans;
    }
};
