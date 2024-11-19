//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:

  	long long p(int a , int b){
  		if(b == 0)return 1;

  		long long temp = (long long) p(a,b/2);

  		if(b%2)return temp*temp*a;
  		return temp*temp; 

  	}
    
    long long count(int n) {

    	int b = n*(n-1)/2;
    	return p(2,b);
       
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.count(n) << "\n";
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends