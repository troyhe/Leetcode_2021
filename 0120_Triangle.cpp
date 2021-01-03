class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = 1; i < triangle.size(); i++){
            triangle[i][0] += triangle[i-1][0];
            triangle[i][i] += triangle[i-1][i-1];
            for (int j = 1; j < i; j++){
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        int minPath = INT_MAX;
        for (int i = 0; i < triangle.size(); i++) minPath = min(minPath, triangle[triangle.size() -1][i]);
        return minPath;
    }
};
