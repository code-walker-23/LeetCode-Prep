//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    const int MOD = 1000000007;
    
    // i have to remove equality one of them otherwise it includes twice duplicate in subarraycount
    // eg ->  _,_,_,58,_,_,58 first 58 has pse = -1 nse = before second 58 and nse = n and second 58 has nse = n and pse = -1
    
    vector<int> previousSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> pse(n, -1);

        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                pse[i] = s.top();
            }
            s.push(i);
        }
        return pse;
    }

    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();
        stack<int> s;
        vector<int> nse(n, n);

        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] > arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nse[i] = s.top();
            }
            s.push(i);
        }
        return nse;
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> pse = previousSmallerElement(arr);
        vector<int> nse = nextSmallerElement(arr);

        long long totalSum = 0;

        for (int i = 0; i < n; i++) {
            long long leftCount = i - pse[i];
            long long rightCount = nse[i] - i;
            totalSum = (totalSum + leftCount * rightCount % MOD * arr[i] % MOD) % MOD;
        }

        return totalSum;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.sumSubarrayMins(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends