class Solution {
public:
    double myPow(double x, int n) {
        long long a = n;
        if(n<0)a = -1*a;

        double ans = 1;

        while(a>0){
            if(a%2){
                ans = ans*x;
                a = a-1;
            }else{
                x = x*x;
                a = a/2;
            }
        }

        if(n<0)return 1/ans;
        return ans;
    }
};