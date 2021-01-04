class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // Construct a monotonic (increasing) stack
        stack<int> heightsIdx;
        heightsIdx.push(-1);
        int largestArea = 0;
        for (int i = 0; i < heights.size(); i++){
            while (heightsIdx.size() > 1 && heights[heightsIdx.top()] > heights[i]){
                int cur = heightsIdx.top();
                heightsIdx.pop();
                int area = heights[cur] * (i - heightsIdx.top() - 1);
                largestArea = max(area, largestArea);
            }
            heightsIdx.push(i);
        }
        while (heightsIdx.size() > 1){
            int cur = heightsIdx.top();
            heightsIdx.pop();
            int area = heights[cur] * (heights.size() - heightsIdx.top() - 1);
            largestArea = max(area, largestArea);
        }
        return largestArea;
    }
};
