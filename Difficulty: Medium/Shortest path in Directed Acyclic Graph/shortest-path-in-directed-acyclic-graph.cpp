//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
// we do not have a problem with negative edges but we have problem with negative weight cycles
class Solution {
  public:
    void topoSort(vector<vector<pair<int,int>>>&adj,int src,vector<int>&vis,stack<int>&topo){
        vis[src] = 1;
        
        for(auto p : adj[src]){
            int u = p.first;
            if(!vis[u])topoSort(adj,u,vis,topo);
        }
        
        topo.push(src);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(V);
        
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back(make_pair(v, wt));
        }
        
        vector<int>vis(V,0);
        stack<int>topo;
        
        for(int i = 0; i < V; i++){
            if(!vis[i])topoSort(adj,i,vis,topo);
        }
        
        
        vector<int>dis(V,1e9);
        dis[0] = 0;
        // we are using topoSort because we do not wanna update the dis of processed node again and again
        
        while(!topo.empty()){
            int top = topo.top();
            topo.pop();
            
            for(auto p : adj[top]){
                int u = p.first;
                int wt = p.second;
                
                if(dis[top] + wt < dis[u])dis[u] = dis[top] + wt;
            }
        }
        
        for(int i = 0; i < V; i++)if(dis[i] == 1e9)dis[i] = -1;
        
        return dis;
    }

};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends