//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& list, int baseX, int baseY) {
        vis[i][j] = 1;
        list.push_back({i - baseX, j - baseY});
        int del[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
        
        for(int k = 0; k < 4; k++) {
            int row = i + del[k][0];
            int col = j + del[k][1];
            
            if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() &&
               !vis[row][col] && grid[row][col] == 1) {
                dfs(row, col, vis, grid, list, baseX, baseY);
            }
        }
    }

    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> se;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> list;
                    dfs(i, j, vis, grid, list, i, j); 
                    se.insert(list);
                }
            }
        }
    
        return se.size();
    }

};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends