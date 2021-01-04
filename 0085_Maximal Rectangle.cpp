class Solution {
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return 0;
        vector<int> heights(matrix[0].size(), 0);
        int largestArea = 0;
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                heights[j] = (matrix[i][j] == '1')?heights[j]+1:0;
            }
            int area = largestRectangleArea(heights);
            largestArea = max(area, largestArea);
        }
        return largestArea;
    }
};
