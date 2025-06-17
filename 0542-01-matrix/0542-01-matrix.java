class Solution {
    // This is bfs problem -> Min Distance
    public int[][] updateMatrix(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;

        Queue<int[]>q = new LinkedList<>();
        int[][] dis = new int[m][n];
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(mat[i][j] == 0){
                    q.add(new int[]{i,j});
                    dis[i][j] = 0;
                }
            }
        }

        int[][] del = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.isEmpty()){
            int[] num = q.remove();
            int u = num[0];
            int v = num[1];

            for(int k = 0; k < 4; k++){
                int nrow = u + del[k][0];
                int ncol = v + del[k][1];

                if(nrow < 0 || nrow == m || ncol < 0 || ncol == n || mat[nrow][ncol] != 1 || dis[nrow][ncol] != 0)continue;

                dis[nrow][ncol] = dis[u][v] + 1;
                q.add(new int[]{nrow,ncol});
            }
        }

        return dis;
    }
}