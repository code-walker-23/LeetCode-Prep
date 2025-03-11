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
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
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
        // cout << dp1[4] << " " << dp2[4] << endl;
        
        // if(maxLen == -1)return 0;
        return n-maxLen;
    }
};