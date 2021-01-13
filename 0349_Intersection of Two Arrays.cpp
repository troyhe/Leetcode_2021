class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_set<int> set1;
        unordered_set<int> set2;
        for (int n: nums1) set1.insert(n);
        for (int n: nums2) set2.insert(n);
        for (auto it: set1){
            if (set2.count(it)){
                ans.push_back(it);
            }
        }
        return ans;
    }
};
