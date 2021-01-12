class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        // keep hi.size() >= lo.size();
        multiset<int, less<int>> hi;
        multiset<int, greater<int>> lo;
        for (int i = 0; i < nums.size(); i++){
            if (i >= k){
                if (nums[i-k] >= *hi.begin()){
                    hi.erase(hi.find(nums[i-k]));
                } else {
                    lo.erase(lo.find(nums[i-k]));
                }
            }
            hi.insert(nums[i]);
            lo.insert(*hi.begin());
            hi.erase(hi.begin());
            
            if (lo.size() > hi.size()){
                hi.insert(*lo.begin());
                lo.erase(lo.begin());
            }
            
            if (i >= k - 1 && k % 2 != 0){
                medians.push_back(*hi.begin());
            } else if (i >= k - 1 && k % 2 == 0){
                medians.push_back((*hi.begin() + *lo.begin())/2.0);
            }
        }
        return medians;
    }
};
