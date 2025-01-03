//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
#define mod 1000000007
vector<int> dp(100000,-1);
class Solution {
  public:
    long long int topDown(int n) {
        if(n == 0 || n == 1)return dp[n] = n;
        if(dp[n] != -1)return dp[n];
        
        return dp[n] = (topDown(n-1)+topDown(n-2))%mod;
    }
    long long int bottomUp(int n) {
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1]+dp[i-2])%mod;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends