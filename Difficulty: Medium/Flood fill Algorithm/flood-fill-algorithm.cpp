//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    void dfs(pair<int,int> s , vector<vector<int>> &image, int newColor){
    
        int i = s.first;
        int j = s.second;
        
        int src_color = image[i][j];
        image[i][j] = newColor;
        
        int drow[] = {1,0,-1,0};
        int dcol[] = {0,1,0,-1};
        
        for(int k = 0; k < 4; k++){
        	int nrow = i + drow[k];
        	int ncol = j + dcol[k];
        	if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size() && image[nrow][ncol] == src_color && src_color != newColor){
        		dfs({nrow,ncol},image,newColor);
        	}
        }


}

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
         int m = image.size();
         int n = image[0].size();
         dfs({sr,sc},image,newColor);
         return image;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends