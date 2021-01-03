class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxScore = INT_MIN;
        int firstScore = A[0] + 0;
        for (int i = 1; i < A.size(); i++){
            maxScore = max(maxScore, A[i] - i + firstScore);
            firstScore = max(firstScore, A[i] + i);
        }
        return maxScore;
    }
};
