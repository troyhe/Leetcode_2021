/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* parent = p;
        unordered_set<Node*> dic;
        while (p){
            dic.insert(p);
            p = p->parent;
        }
        while (q){
            if (dic.find(q) != dic.end()) return q;
            q = q->parent;
        }
        return nullptr;
    }
};
