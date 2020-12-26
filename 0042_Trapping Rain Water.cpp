class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) return 0;
        // vector<int> leftHighest(height.size(), 0);
        // vector<int> rightHighest(height.size(), 0);
        // int maxLeft = height[0];
        // for (int i = 1; i < height.size(); i++){
        //     leftHighest[i] = maxLeft;
        //     maxLeft = max(maxLeft, height[i]);
        // }
        // int maxRight = height[height.size()-1];
        // for (int i = height.size() - 2; i >= 0; i--){
        //     rightHighest[i] = maxRight;
        //     maxRight = max(maxRight, height[i]);
        // }
        // int sum = 0;
        // for (int i = 1; i < height.size() - 1; i++){
        //     sum += max(0, min(leftHighest[i], rightHighest[i]) - height[i]);
        // }
        // return sum;
        
        int left = 0;
        int right = height.size() - 1;
        // the trapping height
        int maxHeight = min(height[left], height[right]);
        int sum = 0;
        while (left < right - 1){
            if (height[left] < height[right]){
                left++;
                sum += max(0, maxHeight - height[left]);
                maxHeight = max(maxHeight, min(height[left],height[right]));
            } else {
                right--;
                sum += max(0, maxHeight - height[right]);
                maxHeight = max(maxHeight, min(height[left],height[right]));
            }
        }
        return sum;
    }
};
