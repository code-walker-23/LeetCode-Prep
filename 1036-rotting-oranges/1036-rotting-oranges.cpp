class Solution {
public:
//  we will be traversing level wise and the last level will be the min minutes to get all rotten
// at max all will rotten then all will go to the queue
// Space  -> O(n*m)
// Time -> O(n*m +  n*m*4 + n*m) = O(n*m)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int time = 0;
        queue<pair<pair<int,int>,int>>q;
        int cntFresh = 0;

        // n*m
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                }else if(grid[i][j] == 1)cntFresh++;
            }
        }

        int newRotten = 0;
        // n*m
        while(!q.empty()){
            pair<pair<int,int>,int> p = q.front();
            q.pop();

            int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
            int i = p.first.first;
            int j = p.first.second;
            time = p.second;

            // n*m*4 time
            for(int k = 0; k < 4; k++){
                int row = i + del[k][0]; 
                int col = j + del[k][1];

                if(row < 0 || row >= n || col < 0 || col >= m)continue;

                if(grid[row][col] == 1){
                    grid[row][col] = 2;
                    q.push({{row,col},p.second+1});
                    newRotten++;
                }

            }

        }

        if(cntFresh != newRotten)return -1;
        return time;
    }
};