class Solution {
public:  
    bool isSubsetSum(int i,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target == 0)return true;
        if(i < 0) return false;

        if(dp[i][target] != -1)return dp[i][target];

        //take this
        if(nums[i] <= target){
            dp[i][target] = isSubsetSum(i-1,target-nums[i],nums,dp) || isSubsetSum(i-1,target,nums,dp);
        }
        
        else{
            dp[i][target] = isSubsetSum(i-1,target,nums,dp);
        }
        
        return dp[i][target];
        
    }


    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        if(sum%2)return false;
        else{
            int s1 = sum/2;
            vector<vector<int>>dp(nums.size(),vector<int>(s1+1,-1));
            return isSubsetSum(nums.size()-1,s1,nums,dp);
        }

    }
};