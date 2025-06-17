class Solution {
public:
int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visited(m,vector<int>(n,0));
    int cntFresh = 0;
    int newRotten = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 2){
                q.push({{i,j},0});
                visited[i][j] = 2;
            }
            if(grid[i][j] == 1)cntFresh++;
        }
    }

    int time = 0;

    while(!q.empty()){
        pair<pair<int,int>,int> front = q.front();
        int r = front.first.first;
        int c = front.first.second;
        int t = front.second;
        q.pop();

        time = t;

        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};

        for(int i = 0; i < 4; i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push({{nrow,ncol},1+t});
                visited[nrow][ncol] = 2;
                newRotten++;
            }
        }
    }
    if(cntFresh != newRotten)return -1;
    return time;
    }
};