class ZigzagIterator {
    int it1;
    int it2;
    bool isIt1;
    vector<int> vec1;
    vector<int> vec2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        it1 = 0;
        it2 = 0;
        isIt1 = !v1.empty();
        vec1 = v1;
        vec2 = v2;
    }

    int next() {
        int ans;
        if (isIt1){
            ans = vec1[it1++];
            if (it2 != vec2.size()) isIt1 = false;
        } else {
            ans = vec2[it2++];
            if (it1 != vec1.size()) isIt1 = true;
        }
        return ans;
    }

    bool hasNext() {
        if (isIt1) return it1 != vec1.size();
        else return it2 != vec2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
