class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row = image.size();
        if (row == 0) return image;
        int col = image[0].size();
        if (col == 0) return image;
        pair<int, int> start = {sr, sc};
        queue<pair<int, int>> q;
        int color = image[sr][sc];
        if (color != newColor) q.push(start);
        while (!q.empty()){
            pair<int, int> px = q.front();
            q.pop();
            image[px.first][px.second] = newColor;
            if (px.first - 1 >= 0 && image[px.first - 1][px.second] == color){
                q.push({px.first - 1, px.second});
            }
            if (px.first + 1 < image.size() && image[px.first + 1][px.second] == color){
                q.push({px.first + 1, px.second});
            }
            if (px.second - 1 >= 0 && image[px.first][px.second - 1] == color){
                q.push({px.first, px.second - 1});
            }
            if (px.second + 1 < image[0].size() && image[px.first][px.second + 1] == color){
                q.push({px.first, px.second + 1});
            }
        }
        return image;
    }
};
