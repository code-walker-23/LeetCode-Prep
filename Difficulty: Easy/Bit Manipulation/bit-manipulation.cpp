//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int mask = 1;
        while(i){
            i--;
            if(i != 0){
                mask <<= 1;
            }
        }
        // mask is ready
        // get the ith bit
        int ithBit = (num & mask) ? 1 : 0;
        int x1 = num | mask;
        int x2 = num & (~mask);
        cout << ithBit << " " << x1 << " " << x2;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends