//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void dfs(int s , vector<vector<int>> adj , vector<int> &dfs_result , vector<bool> &visited ){
        visited[s] = true;
        dfs_result.push_back(s);
        
        for(auto nbrs : adj[s]){
            if(!visited[nbrs]){
                dfs(nbrs,adj,dfs_result,visited);
            }
        }
        
    }
  
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>> adj) {
        int V = adj.size();
        vector<bool> visited(V,false);
        vector<int> dfs_result;
        dfs(0,adj,dfs_result,visited);
        return dfs_result;
        
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(
            V); // Use vector of vectors instead of array of vectors.

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.dfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends