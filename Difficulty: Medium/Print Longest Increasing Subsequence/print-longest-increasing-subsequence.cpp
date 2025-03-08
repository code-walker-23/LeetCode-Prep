//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        if(n == 1)return {nums[0]};
        vector<int>dp(n,1);
        vector<int>track(n,-1);
        int j = 0;
        int maxLen = 0;
        int idx = -1;

        for(int i = 1; i < n; i++){
            while(j != i){
                if(nums[j] < nums[i]){
                    if(dp[j]+1 > dp[i]){
                        track[i] = j;
                        dp[i] = dp[j]+1;
                    }
                }
                j++;
            }
            // find index till that we longest subsequence
            if(maxLen < dp[i])maxLen = dp[i],idx = i;
            j = 0;
        }
        // printing in reverse order
        vector<int>res;
        while(idx != -1){
            // cout << nums[idx] << endl;
            res.push_back(nums[idx]);
            idx = track[idx];
        }
        reverse(res.begin(),res.end());
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends