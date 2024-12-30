//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum money the thief can get.
    int findMaxSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n);

        if(n == 1)return nums[0];
        
        dp[n-1] = nums[n-1];
        dp[n-2] = max(nums[n-1],nums[n-2]);

        for(int i = n-3; i >= 0; i--){
            int max1 = nums[i]+dp[i+2];
            int max2 = dp[i+1];
            dp[i] = max(max1,max2);
        }
        // return maxMoney(0,nums,n,dp);

        return dp[0];
    }
};

//{ Driver Code Starts.

int main() {

    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        // calling function findMaxSum()
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends