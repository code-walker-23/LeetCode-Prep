//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void print(vector<int>& traversal, vector<vector<int>>& matrix, int srow, int erow, int scol, int ecol) {
        // Traverse from left to right along the top row
        for (int i = scol; i <= ecol; i++) 
            traversal.push_back(matrix[srow][i]);

        // Traverse from top to bottom along the right column
        for (int i = srow + 1; i <= erow; i++) 
            traversal.push_back(matrix[i][ecol]);

        // Traverse from right to left along the bottom row, if there are rows remaining
        if (srow < erow) {
            for (int i = ecol - 1; i >= scol; i--) 
                traversal.push_back(matrix[erow][i]);
        }

        // Traverse from bottom to top along the left column, if there are columns remaining
        if (scol < ecol) {
            for (int i = erow - 1; i > srow; i--) 
                traversal.push_back(matrix[i][scol]);
        }
    }
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> traversal;
        
        int srow = 0;
        int scol = 0;
        int erow = row - 1;
        int ecol = col - 1;
        
        while (srow <= erow && scol <= ecol) {
            print(traversal, matrix, srow, erow, scol, ecol);
            srow++; erow--;
            scol++; ecol--;
        }

        return traversal;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r);

        for (int i = 0; i < r; i++) {
            matrix[i].assign(c, 0);
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends