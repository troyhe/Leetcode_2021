class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int seenOnce = 0;
        int seenTwice = 0;
        for (int& n: nums){
            seenOnce = ~seenTwice & (seenOnce ^ n);
            seenTwice = ~seenOnce & (seenTwice ^ n);
        }
        return seenOnce;
    }
};
