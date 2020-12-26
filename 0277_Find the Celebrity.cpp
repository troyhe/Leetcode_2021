/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
    bool checkCandidate(int candidate, int n){
        for (int i = 0; i < n; i++){
            if (candidate == i) continue;
            if (!knows(i, candidate) || knows(candidate, i)) return false;
        }
        return true;
    }
public:
    int findCelebrity(int n) {
        // logical deduction, a tricky method
        int candidate = 0; 
        for (int i = 1; i < n; i++){
            if (knows(candidate, i)){
                candidate = i;
            }
        }
        // check candidate
        if (checkCandidate(candidate, n)) return candidate;
        return -1;
    }
};
