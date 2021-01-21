/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return new TreeNode(head->val);
        ListNode* first = head;
        ListNode* second = head;
        while (first->next && first->next->next){
            first = first->next->next;
            if (first->next) second = second->next;
        }
        TreeNode* right = sortedListToBST(second->next->next);
        TreeNode* root = new TreeNode(second->next->val);
        second->next = nullptr;
        TreeNode* left = sortedListToBST(head);
        root->left = left;
        root->right = right;
        return root;
        
    }
};
