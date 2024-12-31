//{ Driver Code Starts
// C++ program to check if two strings are isomorphic

#include <bits/stdc++.h>

using namespace std;
#define MAX_CHARS 256


// } Driver Code Ends
class Solution {
  public:
    // Function to check if two strings are isomorphic.
    bool areIsomorphic(string &s, string &t) {
        if(s.size() != t.size())return false;

        //mapping if key is already mapped with different char then return false
        //  we can do this via two map to avoid loop in else
        unordered_map<char,char>mapi;
        // n^2 ans space -> n
        // with two map n^ and space 2*n
        for(int i = 0; i < s.size(); i++){
            if(mapi.find(s[i]) != mapi.end()){
                if(mapi[s[i]] != t[i])return false;
            }
            else{
                for(auto p : mapi)if(t[i] == p.second)return false;
                mapi[s[i]] = t[i];
            } 
        }

        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    string s1, s2;
    while (t--) {
        cin >> s1;
        cin >> s2;
        Solution obj;
        int r = obj.areIsomorphic(s1, s2);
        if (r) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends