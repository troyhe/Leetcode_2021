class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        // Utilize monotonic stack (decreasing)
        stack<int> s;
        int prev = INT_MIN;
        // All the nodes should be larger than prev
        for (int node: preorder){
            while (!s.empty() && s.top() < node){
                prev = s.top();
                s.pop();
            }
            if (node < prev) return false;
            s.push(node);
        }
        return true;
    }
};
