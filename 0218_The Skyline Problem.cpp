class Solution {
    struct sky{
        int x;
        int height;
        bool isStart;
        sky(int x, int height, bool isStart):x(x), height(height), isStart(isStart){}
    };
    struct cmpr{
        bool operator() (const sky& s1, const sky& s2){
            if (s1.x == s2.x){
                if (s1.isStart && s2.isStart){
                    return s1.height > s2.height;
                } else if (!s1.isStart && !s2.isStart){
                    return s1.height < s2.height;
                } else {
                    return s1.isStart;
                }
            }
            return s1.x < s2.x;
        }
    };
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<sky> skys;
        for (int i = 0; i < buildings.size(); i++){
            skys.push_back(sky(buildings[i][0], buildings[i][2], true));
            skys.push_back(sky(buildings[i][1], buildings[i][2], false));
        }
        sort(skys.begin(), skys.end(), cmpr());
        multiset<int> q;
        q.insert(0);
        int prev = 0;
        for (int i = 0; i < skys.size(); i++){
            if (skys[i].isStart){
                q.insert(skys[i].height);
            } else {
                q.erase(q.find(skys[i].height));
            }
            int cur = *q.rbegin();
            if (cur != prev){
                ans.push_back({skys[i].x, cur});
                prev = cur;
            }
        }
        return ans;
    }
};
