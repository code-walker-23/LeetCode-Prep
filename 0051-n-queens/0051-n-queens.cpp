class Solution {
public:

    // Function to check if a queen can be placed at (row, col)
    bool isAttacking(vector<vector<char>>& chess, int n, int row, int col) {
        int arr[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        // Check in all 8 directions
        for (int k = 0; k < 8; k++) {
            int x = row, y = col;
            while (true) {
                x += arr[k][0];
                y += arr[k][1];

                if (x < 0 || x >= n || y < 0 || y >= n) break; // Out of bounds
                if (chess[x][y] == 'Q') return true; // Queen found in the path
            }
        }
        return false;
    }

    // Recursive function to solve N-Queens problem
    void nqueens(int row, int n, vector<vector<string>>& ans, vector<vector<char>>& chess) {
        // Base Case: All queens are placed
        if (row == n) {
            vector<string> v;
            for (int i = 0; i < n; i++) {
                string r = "";
                for (int j = 0; j < n; j++) {
                    r += chess[i][j];
                }
                v.push_back(r);
            }
            ans.push_back(v);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (!isAttacking(chess, n, row, col)) {
                chess[row][col] = 'Q';          // Place queen
                nqueens(row + 1, n, ans, chess); // Recur to place queens in next rows
                chess[row][col] = '.';          // Backtrack
            }
        }
    }


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> chess(n, vector<char>(n, '.'));

        nqueens(0, n, ans, chess);
        return ans;
    }
};