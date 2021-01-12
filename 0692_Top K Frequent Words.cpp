class Solution {
    struct cmpr{
        bool operator()(const pair<int, string>& p1, const pair<int, string>& p2){ 
            return (p1.first > p2.first) || (p1.first == p2.first && p1.second < p2.second); 
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> count;
        for (string& s: words){
            count[s]++;
        }
        priority_queue<pair<int, string>, vector<pair<int,string>>, cmpr> pq;
        for (auto it: count){
            if (pq.size() < k){
                pq.push({it.second, it.first});
            } else {
                if (it.second > pq.top().first || (it.second == pq.top().first && it.first < pq.top().second)){
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<string> ans;
        while (!pq.empty()){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
