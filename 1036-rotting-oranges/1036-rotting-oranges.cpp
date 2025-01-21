class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int count = 0;
        queue<pair<pair<int,int>,int>>q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }
            }
        }

        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();

            int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            int i = p.first.first;
            int j = p.first.second;
            count = p.second;

            for(int k = 0; k < 4; k++){
                int row = i + del[k][0]; 
                int col = j + del[k][1];

                if(row < 0 || row >= n || col < 0 || col >= m)continue;

                if(grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push({{row,col},p.second+1});
                }

            }

        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }

        return count;
    }
};