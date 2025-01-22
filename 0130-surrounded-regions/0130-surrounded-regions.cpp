class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        board[i][j] = '#';

        int del[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int k = 0; k < 4; k++) {
            int row = i + del[k][0];
            int col = j + del[k][1];

            if (row >= 0 && row < n && col >= 0 && col < m && board[row][col] == 'O') {
                dfs(row, col, board);
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Step 1: Mark all 'O's connected to the boundary
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(i, 0, board);
            if (board[i][m - 1] == 'O') dfs(i, m - 1, board);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(0, j, board);
            if (board[n - 1][j] == 'O') dfs(n - 1, j, board);
        }

        // Step 2: Replace all 'O's with 'X' and all '#'s back to 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X'; // Surrounded region
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O'; // can't surround
                }
            }
        }
    }
};
