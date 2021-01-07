class Solution {
public:
    int myAtoi(string str) {
        int ans = 0;
        int sign = 1;
        bool isStart = false;
        bool isSign = false;
        for (char x: str){
            switch(x){
                case '-':{
                    if (isStart){
                        return ans * sign;
                    }
                    if (isSign){
                        return ans * sign;
                    }
                    sign = -1;
                    isSign = true;
                    isStart = true;
                    break;
                }
                case '+':{
                    if (isStart){
                        return ans * sign;
                    }
                    if (isSign){
                        return ans * sign;
                    }
                    sign = 1;
                    isSign = true;
                    isStart = true;
                    break;
                }
                case ' ':{
                    if (isStart){
                        return ans * sign;
                    }
                    break;
                }
                default:{
                    if ( x >= '0' && x <= '9'){
                        isStart = true;
                        if (sign == 1 && (ans > (INT_MAX /10) || (ans == (INT_MAX /10) && x > '7'))) return INT_MAX;
                        if (sign == -1 && (ans > (INT_MAX /10) || (ans == (INT_MAX /10) && x > '7'))) return INT_MIN;
                                          
                        ans *= 10;
                        ans += x - '0';
                    } else {
                        return ans * sign;
                    }
                        
                }
                    
            }
            

        }
        return ans * sign;
    }
};
