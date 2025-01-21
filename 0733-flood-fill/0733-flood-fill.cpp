class Solution {
public:
    void dfs(int i,int j,int n,int m,int color,vector<vector<int>>&image){
        int orgColor = image[i][j];
        image[i][j] = color;

        int del[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

        for(int k = 0; k < 4; k++){
            int row = i + del[k][0];
            int col = j + del[k][1];

            if(row < 0 || row >= n || col < 0 || col >= m)continue;

            if(image[row][col] == orgColor && orgColor != color){
			    dfs(row,col,n,m,color,image);
		    }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        // dfs(sr,sc,n,m,color,image);
        
        queue<pair<int,int>>q;
        int orgColor = image[sr][sc];

        q.push({sr,sc});
        image[sr][sc] = color;

        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();

            int i = p.first;
            int j = p.second;

            int del[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

            for(int k = 0; k < 4; k++){
                int row = i + del[k][0];
                int col = j + del[k][1];

                if(row < 0 || row >= n || col < 0 || col >= m)continue;

                if(image[row][col] == orgColor && orgColor != color){
                    image[row][col] = color;
                    q.push({row,col});
                }
            }

        }

        return image;
    }
};