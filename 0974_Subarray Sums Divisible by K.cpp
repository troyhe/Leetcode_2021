class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        // < the residue, num>
        unordered_map<int, int> count;
        int sum = 0;
        count[0] = 1;
        int total = 0;
        for (int n: A){
            sum = ((sum + n) % K + K) % K;
            total += count[sum];
            count[sum]++;
        }
        return total;
    }
};
