class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxV = 0;
        while (left < right){
            int v = min(height[left], height[right]) * (right - left);
            maxV = max(maxV, v);
            if (height[left] < height[right]){
                left ++;
            } else {
                right --;
            }
        }
        return maxV;
    }
    
};
