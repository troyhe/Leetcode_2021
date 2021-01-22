class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        set<pair<string, string>> pairSet;
        for (vector<string>& pair: similarPairs){
            pairSet.insert(make_pair(pair[0], pair[1]));
            pairSet.insert(make_pair(pair[1], pair[0]));
        }
        for (int i = 0; i < sentence1.size(); i++){
            if (sentence1[i] != sentence2[i] && !pairSet.count({sentence1[i], sentence2[i]})) return false;
        }
        return true;
    }
};
