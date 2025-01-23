class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&grid){
        grid[i][j] = 0;

        int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int k = 0; k < 4; k++){
            int row = i + del[k][0];
            int col = j + del[k][1];

            if(row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0)continue;

            dfs(row,col,grid);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1)dfs(0,i,grid);
            if(grid[n-1][i] == 1)dfs(n-1,i,grid);
        }

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1)dfs(i,0,grid);
            if(grid[i][m-1] == 1)dfs(i,m-1,grid);
        }

        int numOfEnclaves = 0;

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(grid[i][j] == 1)numOfEnclaves++;
            }
        }

        return numOfEnclaves;
    }
};