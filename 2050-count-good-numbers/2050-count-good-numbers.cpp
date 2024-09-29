class Solution {
    #define M 1000000007;
public:
    long long myPow(int x, long long n) {
        if(n == 0){
            return 1;
        }    
        long long temp = myPow(x,n/2);
        temp = (temp*temp)%M;
        if(n%2){
            return (temp*x)%M;
        }else{
            return temp;
        }
    }
    int countGoodNumbers(long long n) {
        if(n%2){
            return (myPow(20,n/2)*5)%M;
        }else{
            return myPow(20,n/2);
        }
    }
};