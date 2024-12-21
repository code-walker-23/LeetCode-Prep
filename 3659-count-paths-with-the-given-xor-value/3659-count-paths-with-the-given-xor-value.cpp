#define mod 1000000007
class Solution {
public:
    int totalPaths(int xOR, int i, int j, int m, int n, int k, vector<vector<vector<int>>>& dp, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            xOR ^= grid[i][j];
            return xOR == k ? 1 : 0;
        }

        if (dp[i][j][xOR] != -1) return dp[i][j][xOR];

        int paths = 0;

        // Move down
        if (i + 1 < m) {
            paths = (paths + totalPaths(xOR ^ grid[i][j], i + 1, j, m, n, k, dp, grid)) % mod;
        }

        // Move right
        if (j + 1 < n) {
            paths = (paths + totalPaths(xOR ^ grid[i][j], i, j + 1, m, n, k, dp, grid)) % mod;
        }

        return dp[i][j][xOR] = paths;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(20, -1)));

        return totalPaths(0, 0, 0, m, n, k, dp, grid);
    }
};

