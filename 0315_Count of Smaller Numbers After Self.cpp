class Solution {
    void mergeSort(vector<pair<int,int>>& numsWithIdx, int left, int right, vector<int>& ans){
        if (left + 2 > right) return;
        int mid = (left + right)/2;
        mergeSort(numsWithIdx, left, mid, ans);
        mergeSort(numsWithIdx, mid, right, ans);
        merge(numsWithIdx, left, mid, right, ans);
    }
    
    void merge(vector<pair<int,int>>& numsWithIdx, int left, int mid, int right, vector<int>& ans){
        int i = left;
        int j = mid;
        vector<pair<int,int>> res;
        while (i < mid && j < right){
            // Keep it stable !!
            if (numsWithIdx[i].first <= numsWithIdx[j].first){
                ans[numsWithIdx[i].second]+= j - mid;
                res.push_back(numsWithIdx[i++]);
            } else {
                res.push_back(numsWithIdx[j++]);
            }
        }
        while (i < mid){
            ans[numsWithIdx[i].second]+= j - mid;
            res.push_back(numsWithIdx[i++]);
        }
        while (j < right){
            res.push_back(numsWithIdx[j++]);
        }
        copy(res.begin(), res.end(), &numsWithIdx[left]);
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<pair<int,int>> numsWithIdx(nums.size());
        for (int i = 0; i < nums.size(); i++){
            numsWithIdx[i].first = nums[i];
            numsWithIdx[i].second = i;
        }
        mergeSort(numsWithIdx, 0, nums.size(), ans);
        return ans;
    }
};
