class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        if (n < 0){
            double temp = myPow(x, -(n/2));
            return 1/((n%2 != 0)?x*temp*temp:temp*temp);
        }
        double temp = myPow(x, n/2);
        return (n%2 != 0)?x*temp*temp:temp*temp;
    }
};
