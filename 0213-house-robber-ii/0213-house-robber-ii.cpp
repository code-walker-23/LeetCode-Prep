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
        
        if(n == 1)return nums[0];
        
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);

        return max(maxMoney(1,nums,n,dp1),maxMoney(0,nums,n-1,dp2));
    }
};