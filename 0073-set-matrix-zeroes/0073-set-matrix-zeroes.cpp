class Solution {
public:
   void setZeroes(vector<vector<int>> &matrix){
        vector<pair<int,int>> p;
        int n = matrix.size();
        int m =  matrix[0].size();

        // 1-> means row or col should be same 
        // 0-> means row or col should be filled with zero

        // initially considering the first row and col to be same.
        int row = 1;
        int col = 1;

        // tracking the first row and col, first because we have to mutate this later 

        // iterating the first row
        for(int i = 0; i < m; i++){
            if(matrix[0][i] == 0){
                row = 0;
                break;
            }
        }
         // iterating the first col
        for(int i = 0; i < n; i++){
            if(matrix[i][0] == 0){
                col = 0;
                break;
            }
        }

        // tracking the n-1*m-1 sub-matrix
        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][j] == 0){
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // mutating the original array nased on uypdate

        for(int i = 1; i < n; i++){
            for(int j = 1; j < m; j++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }   
        
        // finally updating the first rown and col
        if(row == 0){
            for(int i = 0; i < m; i++){
                matrix[0][i] = 0;
            }
        }
         if(col == 0){
            for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
            }
        }
    }
};

// Space Complexity -> O(1)
// Time Complexity -> O((m+n)+(m-1*n-1)+(m-1*n-1)+(m+n)) -> O(2(m+n) + 2(m-1*n-1)) -> O(2(m-1*n-1)) -> O(m-1*n-1) -> O(m*n)

// https://leetcode.com/problems/set-matrix-zeroes/solutions/3172908/best-c-4-solution-hash-table-matrix-brute-force-optimize-one-stop-solution