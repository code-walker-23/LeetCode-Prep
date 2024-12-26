//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
        // Function to check if a queen can be placed at (row, col)
    bool isAttacking(vector<vector<int>>& chess, int n, int row, int col) {
        int arr[8][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

        // Check in all 8 directions
        for (int k = 0; k < 8; k++) {
            int x = row, y = col;
            while (true) {
                x += arr[k][0];
                y += arr[k][1];

                if (x < 0 || x >= n || y < 0 || y >= n) break; // Out of bounds
                if (chess[x][y] == 1) return true; // Queen found in the path
            }
        }
        return false;
    }

    // Recursive function to solve N-Queens problem
    void nqueens(int row, int n, vector<vector<int>>&ans, vector<vector<int>>& chess) {
        // Base Case: All queens are placed
        if (row == n) {
            vector<int> v;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if(chess[i][j] != -1)v.push_back(j+1);
                }
            }
            ans.push_back(v);
            return;
        }

        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            if (!isAttacking(chess, n, row, col)) {
                chess[row][col] = 1;          // Place queen
                nqueens(row + 1, n, ans, chess); // Recur to place queens in next rows
                chess[row][col] = -1;          // Backtrack
            }
        }
    }


    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> chess(n, vector<int>(n, -1));

        nqueens(0, n, ans, chess);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends