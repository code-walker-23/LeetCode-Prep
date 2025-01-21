//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int src,int parent,vector<int>&vis,vector<vector<int>>&adj){
    	vis[src] = 1;
    
    	for(auto nbrs : adj[src]){
    		if(vis[nbrs] && nbrs != parent)return true;
    		else if (!vis[nbrs] && dfs(nbrs,src,vis,adj))return true;
    	}
    	return false;
    }
    
    bool bfs(int src,vector<int>&vis,vector<vector<int>>&adj){
    	queue<pair<int,int>>q;
    	vis[src] = 1;
    	q.push({src,-1});
    
    	while(!q.empty()){
    		pair<int,int>p = q.front();
    		q.pop();
    
    		int node = p.first;
    		int parent = p.second;
    
    		for(auto nbrs : adj[node]){
    			if(!vis[nbrs])q.push({nbrs,node}),vis[nbrs]=1;
    			else{
    				if(nbrs != parent)return true;
    			}
    		}
    	}
    
    	return false;
    
    }
    
    bool isCycle(vector<vector<int>>& adj) {
    	int n = adj.size();
    	vector<int>vis(n,0);
        
        // for(int i = 0; i < n; i++){
        //     if(!vis[i]){
        //         if(dfs(i,-1,vis,adj))return true;
        //     }
        // }
    
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(bfs(i,vis,adj))return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends