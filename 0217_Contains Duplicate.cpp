class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> exist;
        for (int n: nums){
            if (exist.count(n)) return true;
            else exist.insert(n);
        }
        return false;
    }
};
