class Solution {
public:
//     int minSum(int i,int j,int n,vector<vector<int>>&matrix,vector<vector<int>>&dp){
//         if(dp[i][j] != -1)return dp[i][j];
//         if(i == n-1)return dp[i][j] = matrix[i][j];
        
//         int leftD = INT_MAX;
//         if(j-1>=0) leftD = matrix[i][j] + minSum(i+1,j-1,n,matrix,dp);
//         int down =  matrix[i][j] + minSum(i+1,j,n,matrix,dp);
//         int rightD = INT_MAX;
//         if(j+1<n)
//             rightD  = matrix[i][j] + minSum(i+1,j+1,n,matrix,dp);
        
        
//         return dp[i][j] = min(min(leftD,rightD),down);

//     }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        vector<vector<int>>dp(n,vector<int>(n));
        
        for(int i = n-1; i>=0; i--){
            for(int j = 0; j < n; j++){
                if(i == n-1)dp[i][j] = matrix[i][j];
                else{
                    int left = INT_MAX;
                    if(j-1>=0) left = matrix[i][j] + dp[i+1][j-1];
                    
                    int right = INT_MAX;
                    if(j+1<n) right = matrix[i][j] + dp[i+1][j+1];
                    
                    int down = matrix[i][j] + dp[i+1][j];
                    
                    dp[i][j] = min(min(left,right),down);
                }
            }
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < n; i++){
            ans = min(ans,dp[0][i]);
        }
        
        return ans;
        
    }
};