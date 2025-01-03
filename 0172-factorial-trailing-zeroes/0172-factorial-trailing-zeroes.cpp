class Solution {
public:
// revision
// Time Complexity -> O(factorial+4) -> O(n=10^4) -> sign overflow
// Space -> O(1)
//  but challenge is logn

// count 2's and 5's number in factorization
    // int trailingZeroes(int n) {
    //     long long fact = 1;
    //     for(int i = 1; i <= n; i++){
    //         fact*=i;
    //     }
    //     int count = 0;
    //     while(fact%10 == 0){
    //         count++;
    //         fact/=10;
    //     }
    //     return count;
    // } 

    // O(n)
    // int trailingZeroes(int n) {
    //     int twosCount = 0;
    //     int fivesCount = 0;

    //     for(int i = 1; i <= n; i++){
    //         int num = i;
    //         while(num%2 == 0){
    //             twosCount++;
    //             num/=2;
    //         }
    //         while(num%5 == 0){
    //             fivesCount++;
    //             num/=5;
    //         }
    //     }

    //     return min(twosCount,fivesCount);

    // }

    // Time Complexity -> (5^k = n) ==> k = logn to the base 5 ==> O(logn) 
    // every 2nd number is  multiple of 2 and every fifth number is multiple of 5
    // when leap from i to i+5 we get three multiple of 2's so we can say that powe of 2 will be greater than the power of 5

    // Thus we will only find the power of 5 which will be the min of 5 and 2 to    form trailing zeroes   
    // int trailingZeroes(int n) {
    //    int count = 0;

    //    for(int i = 5; i <= n; i*=5){
    //     count += n/i;
    //    }
    //    return count;

    // } 

    // recursive approach
    int trailingZeroes(int n) {
       
       return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};