class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            pair<int,int>p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

            for(int k = 0; k < 4; k++){
                int row = i + del[k][0];
                int col = j + del[k][1];

                if(row < 0 || row >= n || col < 0 || col >= m)continue;

                if(!vis[row][col] && mat[row][col]){
                    vis[row][col] = 1;
                    dis[row][col] = 1 + dis[i][j];
                    q.push({row,col});
                }else if(vis[row][col] && mat[row][col]){
                    dis[row][col] = min(dis[row][col],1+dis[i][j]);
                }
            }

        }

        return dis;
    }
};