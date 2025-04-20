class Solution {
public:
    bool dfs(int start, int i, int j, vector<vector<char>>& board, string& word) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size())
            return false;

        if (board[i][j] != word[start])
            return false;

        if (start == word.size() - 1)
            return true;

        // char temp = board[i][j];
        board[i][j] = '$'; // Mark as visited

        int del[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (int k = 0; k < 4; k++) {
            int nrow = i + del[k][0];
            int ncol = j + del[k][1];

            if (dfs(start + 1, nrow, ncol, board, word))
                return true;
        }

        board[i][j] = word[start]; // Restore original char
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(0, i, j, board, word))
                    return true;
            }
        }
        return false;
    }
};
