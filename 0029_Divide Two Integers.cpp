class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int numOfNeg = 2;
        if (dividend == 0) return 0;
        if (dividend > 0){
            dividend = -dividend;
            numOfNeg--;
        }
        if (divisor > 0){
            divisor = -divisor;
            numOfNeg--;
        }
        int value = divisor;
        int n = -1;
        while (value >= INT_MIN/2 && value + value >= dividend){
            value += value;
            n += n;
        }
        int quotient = 0;
        while (dividend <= divisor){
            if (dividend <= value){
                dividend -= value;
                quotient += n;    
            }
            n >>= 1;
            value >>= 1;
        }
        if (numOfNeg == 1) return quotient;
        return -quotient;
    }
};
