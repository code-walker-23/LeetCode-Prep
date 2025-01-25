//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // this can be done in two ways either via xor with(n) and sorting (nlogn)
        int n = arr.size();
        int occ[n+1] = {0};
        int mis = 0;
        int rep = 0;
        
        for(int i = 0; i < n; i++)occ[arr[i]]++;
        
        for(int i = 1; i <= n; i++){
            if(occ[i] == 0)mis = i;
            else if(occ[i] == 2)rep = i;
        }
        
        return {rep,mis};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends