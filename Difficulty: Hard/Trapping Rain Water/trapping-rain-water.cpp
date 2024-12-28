//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

    // Function to find the trapped water between the blocks.
  public:
    int trappingWater(vector<int> &height) {
         // precomputing leftmax and rightmax for every element
        int n = height.size();
        vector<int>leftMax(n);
        vector<int>rightMax(n);

        leftMax[0] = INT_MIN;
        for(int i = 1; i < n-1; i++)leftMax[i] = max(height[i-1],leftMax[i-1]);
        rightMax[n-1] = INT_MIN;
        for(int i = n-2; i >= 0; i--)rightMax[i] = max(height[i+1],rightMax[i+1]);

        // for(int i = 0; i < n; i++){
        //     cout << height[i] << "-> leftMax = " << leftMax[i] << " and " << "rightMax = " << rightMax[i] << endl;
        // }

        int totalWater = 0;
        for(int i = 1; i < n-1; i++){
            int capacity = min(leftMax[i],rightMax[i]) - height[i];
            if(capacity > 0)totalWater += capacity; 
        }

        return totalWater;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.trappingWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends