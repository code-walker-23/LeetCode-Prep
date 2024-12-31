//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s, string& t) {
        int count[26]{0};

        for(auto &ch : s)count[ch-'a']++;
        for(auto &ch : t)count[ch-'a']--;

        bool allZeros = all_of(begin(count),end(count),[](int element){
            return element == 0;
        });
        // return false if there is non-zero
        return allZeros;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends