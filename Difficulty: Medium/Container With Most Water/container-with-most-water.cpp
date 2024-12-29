//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxArea(vector<int> &height) {
        int l = 0;
        int r = height.size()-1;
        int maxCap = 0;

        while(l < r){
            int totalArea = (r-l)*min(height[l],height[r]);
            maxCap = max(maxCap,totalArea);

            if(height[l] <= height[r])l++;
            else r--;
        }

        return maxCap;
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
        int res = ob.maxArea(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends