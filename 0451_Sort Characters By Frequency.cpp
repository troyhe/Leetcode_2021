class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> dic;
        for (char c: s){
            dic[c]++;
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, less<pair<int,char>>> pq;
        for (auto it: dic){
            pq.push({it.second, it.first});
        }
        string ans = "";
        while (!pq.empty()){
            pair<int,char> temp = pq.top();
            pq.pop();
            for (int i = 0; i < temp.first; i++){
                ans += temp.second;
            }
        }
        return ans;
    }
};
