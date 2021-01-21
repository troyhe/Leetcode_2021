class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> map;
        for (int n: nums){
            map.insert(n);
        }
        int maxlength = 0;
        // int length = 0;
        for (auto it: map){
            if (!map.count(it-1)){
                int cur = it + 1;
                int length = 1;
                while (map.count(cur)){
                    length++;
                    cur++;
                }
                maxlength = max(maxlength, length);
            }
        }
        return maxlength;
    }
};
