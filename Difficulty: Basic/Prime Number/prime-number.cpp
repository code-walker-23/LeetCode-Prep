//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPrime(int n) {
        // naive approach 
        
        // Time Complexity -> O(n)
        // Space -> O(1)
        
       
        if(n == 1)return false;
        
        // for(int i = 2; i < n; i++)
        //     if(n%i == 0)return false;
            
        // return true;
        
        // Better -> O(sqrt(n)) -> find divisors in sqrt(n)
        // n = xy ==> then x and y , one will be greater than the root and other will lesser than the root
        // for(int i = 2; i*i <= n; i++){
        //     if(n%i == 0)return false;

        // }
        // return true;
        
        // Optimal Solution for large n
        
        if(n == 2 || n == 3)
            return true;
        if(n%2 == 0 || n%3 == 0)
            return false;
            
        for(int i = 5; i*i <= n; i+=6){
            if(n%i == 0 || n%(i+2) == 0)
                return false;
        }
        
        return true;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << (ob.isPrime(N) ? "true" : "false") << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends