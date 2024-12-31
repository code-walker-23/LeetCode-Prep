//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s, string &goal) {
        if(s.size() != goal.size())return false;
        if(s == goal) return true;

        int n = s.size();
        // efficient
        // when we concatenate a string with itself we get all possible rotations

        s = s+s;
        // we know goal is created by doing rotations now we can check it is a valid rotation or not
        // for(int i = 1; i <= n; i++){
        //     if(s.substr(i,n) == goal)return true;
        // }

        // return false;
        // one liner

        return s.find(goal) != string::npos;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
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