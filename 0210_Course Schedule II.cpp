class Solution {
    bool dfs(vector<vector<int>>& preList, int courseID, vector<int>& done, vector<int>& todo, vector<int>& order){
        todo[courseID] = true;
        for (int course: preList[courseID]){
            if (done[course]) continue;
            if (todo[course]) return false;
            if (!dfs(preList, course, done, todo, order)) return false;
        }
        done[courseID] = true;
        order.push_back(courseID);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preList(numCourses);
        vector<int> order;
        for (vector<int> course: prerequisites){
            preList[course[0]].push_back(course[1]);
        }
        vector<int> done(numCourses, false);
        vector<int> todo(numCourses, false);
        for (int i = 0; i < numCourses; i++){
            if (done[i]) continue;
            if (!dfs(preList, i, done, todo, order)) return vector<int>(0);
        }
        return order;
    }
};
