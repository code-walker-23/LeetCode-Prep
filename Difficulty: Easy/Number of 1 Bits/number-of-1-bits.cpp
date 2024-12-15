//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBits(int n) {
        int tab[256];
        tab[0] = 0;
        
        // this is the most optimal solution O(256) = O(1) better than traversing the the whole floor(logn)+1 bits or the set bits only using Brian Kernighan's algorithm 
        for(int i = 1; i < 256; i++){
            tab[i] = tab[i&(i-1)] + 1;
        }
        
        return tab[n&255] + tab[(n>>8)&255] + tab[(n>>16)&255] + tab[(n>>24)&255];
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
        int cnt = ob.setBits(N);
        cout << cnt << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends