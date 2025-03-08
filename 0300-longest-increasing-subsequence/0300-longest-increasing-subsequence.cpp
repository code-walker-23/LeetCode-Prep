class Solution {
public:
    int lenOfLIS(int idx,int prev,vector<int>&nums,vector<vector<int>>&dp){
        // when we hit the base case, we get one LIS and store the length if it is max then update
        if(idx == nums.size())return 0;

        if(dp[idx][prev] != -1)return dp[idx][prev]; 

        int pick = 0;
        int notPick = 0;

        //picking
        if(prev == 0 || nums[idx] > nums[prev-1]){
            pick = 1 + lenOfLIS(idx+1,idx+1,nums,dp);
        }
        // not pick the idx
        notPick = lenOfLIS(idx+1,prev,nums,dp);

        return dp[idx][prev] = max(pick,notPick);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return lenOfLIS(0,0,nums,dp);
    }
};