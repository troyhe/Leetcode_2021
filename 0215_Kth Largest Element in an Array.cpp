class Solution {
    int partition(vector<int>& nums, int left, int right){
        int pivot = --right;
        while (true){
            while (nums[left] < nums[pivot]) left++;
            while (left < right && nums[right-1] >= nums[pivot]) right--;
            if (left >= right) break;
            swap(nums[left], nums[right-1]);
        }
        swap(nums[left], nums[pivot]);
        return left;
    }
    int findKthLargestHelper(vector<int>& nums, int left, int right, int k){
        // Default:
        if (left + 1 >= right) return nums[k];
        int pivot = partition(nums, left, right);
        if (pivot == k) return nums[k];
        if (pivot < k) return findKthLargestHelper(nums, pivot + 1, right, k);
        return findKthLargestHelper(nums, left, pivot, k);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargestHelper(nums, 0, nums.size(), nums.size() - k);
        // // the top one should be the smallest one;
        // priority_queue<int, vector<int>, greater<int>> pq;
        // for (int i = 0; i < k; i++){
        //     pq.push(nums[i]);
        // }
        // for (int i = k; i < nums.size(); i++){
        //     if (nums[i] > pq.top()){
        //         pq.pop();
        //         pq.push(nums[i]);
        //     }
        // }
        // return pq.top();
        
    }
};
