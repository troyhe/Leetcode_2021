class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        unordered_map<long, long> buckets;
        for (int i = 0; i < nums.size(); i++){
            long val = (long) nums[i] + INT_MIN;
            long label = val;
            if (t > 0) label /= t;
            if (buckets.find(label) != buckets.end()) return true;
            if (buckets.find(label+1) != buckets.end() && buckets[label+1] - val <= t) return true;
            if (buckets.find(label-1) != buckets.end() && val - buckets[label-1] <= t) return true;
            buckets[label] = val;
            if (i >= k){
                long toErase = (long) nums[i-k] + INT_MIN;
                if (t > 0) toErase /= t;
                buckets.erase(toErase);
            }
        }
        return false;
    }
};
