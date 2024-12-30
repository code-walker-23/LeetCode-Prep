class Solution {
public:
    int maxMoney(int idx,vector<int>&nums,int n,vector<int>&dp){
        if(idx == n)return 0;
        if(idx == n-1)return nums[idx];

        if(dp[idx] != -1)return dp[idx];
        //considering idx for robbery and finding maxMoney from next non-adjacent
        int max1 = nums[idx] + maxMoney(idx+2,nums,n,dp);
        // excluding this and consdering it's adjacent
        int max2 = maxMoney(idx+1,nums,n,dp);

        return dp[idx] = max(max1,max2);
    }
    int rob(vector<int>& nums) {
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