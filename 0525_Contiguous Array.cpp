class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int moreZero = 0;
        unordered_map<int, int> dic;
        int maxLength = 0;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) moreZero++;
            else moreZero--;
            if (moreZero == 0) maxLength = max(maxLength, i+1);
            if (dic.find(moreZero) != dic.end()) maxLength = max(maxLength, i -dic[moreZero]);
            else dic[moreZero] = i;
        }
        return maxLength;
    }
};
