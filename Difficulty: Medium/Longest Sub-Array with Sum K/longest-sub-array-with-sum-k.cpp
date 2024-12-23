//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        // brute force
        
        // int maxLength = INT_MIN;
        // int n = arr.size();
        
        // for(int i = 0; i < n; i++){
        //     int sum = 0;
        //     for(int j = i; j < n; j++){
        //         sum+=arr[j];
        //         if(sum == k){
        //             maxLength = max(maxLength,j-i+1);       
        //         }
        //     }
        // }
        
        // return maxLength;
        
        int n = arr.size();
        int sum = 0;
        int maxLen = 0;
        unordered_map<int,int> mapi;
        
        for(int i = 0; i < n; i++){
            sum+=arr[i];
            if(mapi.find(sum) == mapi.end())mapi[sum] = i;
            if(sum == k)maxLen = max(maxLen,i+1);
            if(mapi.find(sum-k) != mapi.end()){
                int start = mapi[sum-k]+1;
                maxLen = max(maxLen,(i-start+1));
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.lenOfLongestSubarr(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends