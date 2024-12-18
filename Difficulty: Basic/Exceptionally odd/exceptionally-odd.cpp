//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        // naive approach
        // O(n) space and time 
        map<int,int>mapi;
        for(int i = 0; i < n; i++)mapi[arr[i]]++;
        for(auto p : mapi){
            if(p.second%2)return p.first;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getOddOccurrence(arr, n);
        cout << ans << "\n";
    
cout << "~" << "\n";
}
    return 0;
}


// } Driver Code Ends