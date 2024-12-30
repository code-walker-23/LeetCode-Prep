//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string removeOuter(string& s) {
        int n = s.size();
        stack<char> st;
        string ans;
        
        int prev = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                if(i > prev)ans+=s[i];
                st.push(s[i]);
            }
            else{
                st.pop();
                if(!st.empty())ans+=s[i];
                else prev = i+1;
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;

        cout << obj.removeOuter(s) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends