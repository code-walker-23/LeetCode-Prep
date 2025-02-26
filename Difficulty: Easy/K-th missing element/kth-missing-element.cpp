//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
   int KthMissingElement(vector<int> &arr, int k) {
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Number of missing elements before arr[mid]
        int missing = arr[mid] - arr[0] - mid;

        // If there are more missing elements than k, move left
        if (missing >= k) {
            high = mid - 1;
        } else {
            // Otherwise, move right
            low = mid + 1;
        }
    }

    // At this point, low is the first position where the missing element count is >= k
    if (low == arr.size()) {
        // If low reaches the end of the array, return the next element after the last element
        return -1;
    }

    // Otherwise, calculate the missing element
    return arr[0] + low + k - 1;
}

};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.KthMissingElement(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends