class Solution {
    public void dfs(int i,int j,char[][] board){
        board[i][j] = '#';

        int[][] del = {{1,0},{-1,0},{0,-1},{0,1}};
        for(int k = 0; k < 4; k++){
            int nrow = i + del[k][0];
            int ncol = j + del[k][1];

            if(nrow < 0 || nrow == board.length || ncol < 0 || ncol == board[0].length || board[nrow][ncol] != 'O')continue;
            dfs(nrow,ncol,board);
        }
    }
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if((i == 0 || i == m-1 || j == 0 || j == n-1) && board[i][j] == 'O'){
                    dfs(i,j,board);
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == '#')board[i][j] = 'O';
            }
        }

    }
}