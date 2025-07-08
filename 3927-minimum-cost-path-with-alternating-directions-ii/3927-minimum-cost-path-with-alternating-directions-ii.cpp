class Solution {
public:
    using ll = long long;
    ll f(ll i, ll j, ll parity, vector<vector<int>>& waitCost, vector<vector<vector<ll>>>& dp){
        if(i == waitCost.size()-1 && j == waitCost[0].size()-1) return 0;
        if(i == waitCost.size() || j == waitCost[0].size()) return 1e15;
        if(dp[i][j][parity] != -1) return dp[i][j][parity];

        ll ans = LLONG_MAX;
        if(parity%2 == 1){
            ans = min(ans, (i + 2)*(j + 1) + f(i + 1, j, 0, waitCost, dp));
            ans = min(ans, (i + 1)*(j + 2) + f(i, j + 1, 0, waitCost, dp));
        } else ans = (waitCost[i][j] + f(i, j, 1, waitCost, dp));

        return dp[i][j][parity] = ans;
    }
    
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<vector<ll>>> dp(m, vector<vector<ll>> (n, vector<ll> (2, -1)));
        return 1 + f(0, 0, 1, waitCost, dp);
    }
};

// class Solution {
// public:
//     const int n = 100001;

//     long long solve(int i,int j,vector<vector<int>>& waitCost,int sec, vector<vector<vector<long long>>> &dp){
//         if(i == waitCost.size()-1 && j == waitCost[0].size()-1)return 0;
//         if(dp[i][j][sec] != -1)return dp[i][j][sec];

//         long long right = -1,down = -1;

//         if(i+1 < waitCost.size()){
//             down = (i+2)*(j+1) + solve(i+1,j,waitCost,0,dp);
//         }

//         if(j+1 < waitCost[0].size()){
//             right = (i+1)*(j+2) + solve(i,j+1,waitCost,0,dp);
//         }
    
//         long long entryCost = 0;
//         if(sec%2 == 0)entryCost = waitCost[i][j];

//         if(right == -1)return dp[i][j][sec] = entryCost + down;
//         if(down == -1)return dp[i][j][sec] = entryCost + right;

//         return dp[i][j][sec] = entryCost + min(right,down);
//     }

//     long long minCost(int m, int n, vector<vector<int>>& waitCost) {
//         vector<vector<vector<long long>>> dp(m, vector<vector<long long>> (n, vector<long long> (2, -1)));

//         return solve(0,0,waitCost,1,dp)+1;
//     }
// };