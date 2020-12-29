/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if (!root) return ans;
        queue<Node*> level;
        level.push(root);
        while (!level.empty()){
            int size = level.size();
            Node* cur;
            vector<int> temp;
            for (int i = 0; i < size; i++){
                cur = level.front();
                level.pop();
                temp.push_back(cur->val);
                for (Node* child: cur->children){
                    level.push(child);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
