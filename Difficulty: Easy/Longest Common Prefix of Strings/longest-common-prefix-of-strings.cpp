//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> strs) {
        int n = strs.size();
        string lcp = "";

        sort(strs.begin(),strs.end());
        
        for(int i = 0; i < min(strs[n-1].size(),strs[0].size()); i++){
            if(strs[0][i] != strs[n-1][i])return lcp;
            else lcp += strs[0][i];
        }

        return lcp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        string ans = ob.longestCommonPrefix(arr);
        if (ans.empty())
            cout << "\"\"";
        else
            cout << ans;
        cout << endl;
    }
}

// } Driver Code Ends