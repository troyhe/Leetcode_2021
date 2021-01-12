class Solution {
    struct bucket{
        int minVal;
        int maxVal;
        bool used;
        bucket():minVal(INT_MAX), maxVal(INT_MIN), used(false){}
    };
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        // MaximunGap must be larger than the bucket size
        int bucketSize = max((maxVal - minVal)/((int)nums.size() - 1), 1);
        int bucketNum = (maxVal - minVal)/ bucketSize + 1;
        vector<bucket> buckets(bucketNum);
        for (int n: nums){
            int bucketIdx = (n - minVal)/bucketSize;
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minVal = min(buckets[bucketIdx].minVal, n);
            buckets[bucketIdx].maxVal = max(buckets[bucketIdx].maxVal, n);
        }
        int maxGap = 0;
        int prev = minVal;
        for (int i = 0; i < bucketNum; i++){
            if (buckets[i].used){
                maxGap = max(maxGap, buckets[i].minVal - prev);
                prev = buckets[i].maxVal;
            }
        }
        return maxGap;
    }
};
