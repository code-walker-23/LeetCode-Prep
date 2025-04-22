class Solution {
public:
    int minCoins(int i,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount == 0)return 0;
        if(i == coins.size() || amount < 0)return -1;
        // we have to take -2 as initialized value otherwise give tle -> it will confuse that dp[i][amount] == -1 it is initialized value or the computed one it will copmute again if it is computed
        // we will take -2 as our initialized value so it will compute only for when dp[i][amount] == -2
        if(dp[i][amount] != -2)return dp[i][amount];

        int min1 = minCoins(i,amount-coins[i],coins,dp);
        if(min1 != -1)dp[i][amount] = 1+min1;
        
        int min2 = minCoins(i+1,amount,coins,dp);
        if(min2 != -1 && dp[i][amount] != -2)dp[i][amount] = min(dp[i][amount],min2);
        if(min2 != -1 && dp[i][amount] == -2)dp[i][amount] = min2;

        // we can not make amount from i index to the last index
        if(dp[i][amount] == -2)return dp[i][amount] = -1; 
        return dp[i][amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-2));
        return minCoins(0,amount,coins,dp);
    }
};