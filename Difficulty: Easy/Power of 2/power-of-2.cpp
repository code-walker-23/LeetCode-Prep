//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to check if given number n is a power of two.
    // logn
    bool isPowerofTwo(int n) {
        if(n == 0)return false;
        
        while(n != 1){
            if(n%2)return false;
            n/=2;
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver code
int main() {

    int t;
    cin >> t; // testcases

    for (int i = 0; i < t; i++) {
        int n; // input a number n
        cin >> n;
        Solution ob;
        if (ob.isPowerofTwo(n))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends