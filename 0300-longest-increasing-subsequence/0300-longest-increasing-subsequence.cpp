class Solution {
public:
// [-1,n-1] aftetr shifting -> [0,n]
// / Time and space -> O(n^2)
    int maxLenLIS(int idx,int prevIdx,vector<int>&nums,vector<vector<int>>&dp){
       if(idx == nums.size())return 0;
        if(dp[idx][prevIdx+1] != -1)return dp[idx][prevIdx+1];

        int maxLen = 0;
        // inclusion
        if(prevIdx == -1 || nums[idx] > nums[prevIdx])maxLen = max(maxLen,maxLenLIS(idx+1,idx,nums,dp)+1);
        // exclusion
        maxLen = max(maxLen,0+maxLenLIS(idx+1,prevIdx,nums,dp));
        // co-ordinate shifting
        return dp[idx][prevIdx+1] = maxLen;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // we will start with prevIdx = -1 then we will do co-ordinate shift
        return maxLenLIS(0,-1,nums,dp);
    }
};


// we have to memoize this and prev will now contain the index
// class Solution {
// public:
//     void maxLenLIS(int idx,vector<int>nums,int prev,int count,int &maxLen){
//         if(idx == nums.size()){
//             maxLen = max(maxLen,count);
//             return;
//         }

//         if(nums[idx] > prev){
//             count++;
//             maxLenLIS(idx+1,nums,nums[idx],count,maxLen);
//             count--;
//         }

//         maxLenLIS(idx+1,nums,prev,count,maxLen);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int maxLen = 0;
//         maxLenLIS(0,nums,INT_MIN,0,maxLen);
//         return maxLen;
//     }
// };



// Brute Force
// class Solution {
// public:
// // Brute Force Soltuion -> O(2^n * k) and Space -> O(n*k) -> TLE solve with DP
//     bool isIncSub(vector<int>arr){
//         for(int i = 1; i < arr.size(); i++){
//             if(arr[i] <= arr[i-1])return false;
//         }
//         return true;
//     }

//     void generateAllSubsequences(int idx,vector<int>&nums,vector<int>&subset,int &maxLen){
//         if(idx == nums.size()){
//             int size = subset.size();
//             if(isIncSub(subset))maxLen = max(maxLen,size);
//             return;
//         }
        
//         subset.push_back(nums[idx]);
//         generateAllSubsequences(idx+1,nums,subset,maxLen);
//         subset.pop_back();
//         generateAllSubsequences(idx+1,nums,subset,maxLen);
//     }

//     int lengthOfLIS(vector<int>& nums) {
//         int maxLen = 0;
//         vector<int>subset;
        
//         generateAllSubsequences(0,nums,subset,maxLen);
//         return maxLen;
//     }
// };



// Own Implemented -> Need to correct this
    // int maxLenLIS(int idx,int prevIdx,vector<int>&nums,vector<vector<int>>&dp){
    //     if(idx == nums.size()-1){
    //         if(prevIdx == nums.size() || nums[prevIdx] < nums[idx])return 1;
    //         return 0;
    //     }
    //     if(prevIdx == nums.size()){
    //         int pick = maxLenLIS(idx+1,0,nums,dp) + 1;
    //         int notPick = maxLenLIS(idx+1,nums.size(),nums,dp);

    //         return dp[idx][nums.size()] = max(pick,notPick);
    //     }
    //     if(dp[idx][prevIdx] != -1)return dp[idx][prevIdx];

    //     int maxLen = INT_MIN;
    //     if(nums[idx] > nums[prevIdx])
    //         maxLen = max(maxLen,maxLenLIS(idx+1,idx,nums,dp)+1);
    //     maxLen = max(maxLen,maxLenLIS(idx+1,prevIdx,nums,dp));

    //     return dp[idx][prevIdx] = maxLen;
    // }