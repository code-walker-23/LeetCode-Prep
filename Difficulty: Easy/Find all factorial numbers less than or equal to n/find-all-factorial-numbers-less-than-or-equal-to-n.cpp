//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long factorial(int num){
        long long fac = 1;
        for(int i = 2; i <= num; i++){
            fac *= i;
        }
        return fac;
    }
    vector<long long> factorialNumbers(long long n) {
       vector<long long>factorials;
       int i = 1;
       while(true){
           long long fac = factorial(i);
           if(fac <= n){
               factorials.push_back(fac);
               i++;
           }
           else{
               break;
           }
       }
       return factorials;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends