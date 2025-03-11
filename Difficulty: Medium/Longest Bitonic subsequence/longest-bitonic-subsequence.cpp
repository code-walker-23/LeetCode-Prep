//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends


class Solution {
  public:
    void lis(vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i])dp[i] = dp[j]+1;
            }
        }
    }
    void lds(vector<int>&nums,vector<int>&dp){
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            for(int j = n-1; j > i; j--){
                if(nums[j] < nums[i] && dp[j]+1 > dp[i])dp[i] = dp[j]+1;
            }
        }
    }
    int LongestBitonicSequence(int n, vector<int> &nums) {
        vector<int>dp1(n,1);
        vector<int>dp2(n,1);
        
        lis(nums,dp1);
        lds(nums,dp2);
        
        int maxLen = -1;
        for(int i = 0; i < n; i++){
            // there must be increasing and decreasing
            if(dp2[i] > 1 && dp1[i] > 1){
                maxLen = max(maxLen,dp1[i]+dp2[i]-1);
            }
        }
        
        if(maxLen == -1)return 0;
        return maxLen;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends