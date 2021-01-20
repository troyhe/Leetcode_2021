/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node*, Node*> dic;
    Node* cloneHelper(Node* node){
        if (dic.find(node) == dic.end()){
            Node* copy = new Node(node->val);
            dic[node] = copy;
            for (Node* neighbor: node->neighbors){
                copy->neighbors.push_back(cloneHelper(neighbor));
            }
            return copy;
        } else return dic[node];
        return nullptr;
    }
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        return cloneHelper(node);
    }
};
