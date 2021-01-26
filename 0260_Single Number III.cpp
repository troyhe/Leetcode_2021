class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for (int& n: nums) bitmask ^= n;
        int diff = (bitmask == INT_MIN)?1:bitmask & (-bitmask); // The rightmost 1 for the number (a XOR b)
        int x = 0;
        for (int& n: nums) if ((n & diff) == 0) x ^= n;
        return vector<int>{x, bitmask^x};
    }
};
