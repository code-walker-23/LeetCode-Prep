class Solution {
public:
    double myPow(double x, int n) {
        // x^0 -> becomes 1
        if(n == 0){
            return 1;
        }    
        double temp = myPow(x,n/2);
        temp *= temp;
        // if x is odd then -> x^37 -> x^18 * x^18 * x 
        if(n%2){
            return n < 0 ? temp*1/x : temp*x;
        }else{
            return temp;
        }
    }
};