class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        // < restaurant name, smallest idx>
        unordered_map<string, int> map1;
        unordered_map<string, int> map2;
        int smallestIdx = INT_MAX;
        vector<string> ans;
        for (int i = 0; i < max(list1.size(), list2.size()) && i <= smallestIdx; i++){
            if (i < list1.size()){
                if (map1.find(list1[i]) == map1.end()){
                    map1[list1[i]] = i;
                }
                if (map2.find(list1[i]) != map2.end()){
                    int idx = i + map2[list1[i]];
                    if (idx < smallestIdx){
                        ans = vector<string>(1, list1[i]);
                        smallestIdx = idx;
                    } else if (idx == smallestIdx){
                        ans.push_back(list1[i]);
                    }
                }
            }
            if (i < list2.size()){
                if (map2.find(list2[i]) == map2.end()){
                    map2[list2[i]] = i;
                }
                if (map1.find(list2[i]) != map1.end()){
                    int idx = i + map1[list2[i]];
                    if (idx < smallestIdx){
                        ans = vector<string>(1, list2[i]);
                        smallestIdx = idx;
                    } else if (idx == smallestIdx){
                        ans.push_back(list2[i]);
                    }
                }
            }
        }
        return ans;
    }
};
