class Solution {
    struct cmpr{
        bool operator()(const vector<string>& s1, const vector<string>& s2){
            return s1[1] < s2[1];
        }
    };
    
    void dfs(vector<string>& ans, string cur, unordered_map<string, vector<pair<string, bool>>>& map){
        for (pair<string, bool>& ticket: map[cur]){
            if (!ticket.second){
                ticket.second = true;
                dfs(ans, ticket.first, map);
            }
        }
        ans.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), cmpr());
        unordered_map<string, vector<pair<string, bool>>> map;
        for (vector<string>& ticket: tickets){
            map[ticket[0]].push_back({ticket[1], false});
        }
        vector<string> ans;
        string source = "JFK";
        dfs(ans, source, map);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
