//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> graph[]) {
        int n = V;
        vector<int>indegree(n,0);
        vector<vector<int>> adj(n);
        vector<int>safeNodes;
        queue<int>q;

        // reversing the edges
        for(int i = 0; i < n; i++){
            // outdegree becomes the indegree , now node with indegree 0 is terminal = safe node
            indegree[i] = graph[i].size();
            if(indegree[i] == 0)q.push(i);
            for(auto nbr : graph[i]){
                adj[nbr].push_back(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safeNodes.push_back(node);

            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)q.push(nbr);
            }
        }
        sort(safeNodes.begin(),safeNodes.end());
        return safeNodes;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    
cout << "~" << "\n";
}
}

// } Driver Code Ends