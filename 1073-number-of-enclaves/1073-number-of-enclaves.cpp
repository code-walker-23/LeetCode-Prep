class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> visited(m, vector<int>(n,0));
        queue<pair<int,int>> q;

        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(i == 0 || j == 0 || i == m-1 || j == n-1){
                    visited[i][j] = 1;
                    if(grid[i][j]==1) q.push({i,j});
                }
                else if(grid[i][j] == 1){
                    count++;
                }
            }
        }

        int delrow[] = {0, 0, -1, 1};
        int delcol[] = {-1, 1, 0, 0};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 1 && !visited[nrow][ncol]){
                    count--;
                    visited[nrow][ncol] = 1;
                    q.push({nrow,ncol});   
                }
            }
        }
        return count;
    }
    // void dfs(int i,int j,vector<vector<int>>&grid){
    //     grid[i][j] = 0;

    //     int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    //     for(int k = 0; k < 4; k++){
    //         int row = i + del[k][0];
    //         int col = j + del[k][1];

    //         if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0)continue;

    //         dfs(row,col,grid);
    //     }
    // }

    // int numEnclaves(vector<vector<int>>& grid) {
    //     int n = grid.size();
    //     int m = grid[0].size();

    //     for(int i = 0; i < m; i++){
    //         if(grid[0][i] == 1)dfs(0,i,grid);
    //         if(grid[n-1][i] == 1)dfs(n-1,i,grid);
    //     }

    //     for(int i = 0; i < n; i++){
    //         if(grid[i][0] == 1)dfs(i,0,grid);
    //         if(grid[i][m-1] == 1)dfs(i,m-1,grid);
    //     }

    //     int numOfEnclaves = 0;

    //     for(int i = 1; i < n; i++){
    //         for(int j = 1; j < m; j++){
    //             if(grid[i][j] == 1)numOfEnclaves++;
    //         }
    //     }

    //     return numOfEnclaves;
    // }
};