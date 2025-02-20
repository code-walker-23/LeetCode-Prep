class Solution {
public:
// simple concept via topo sort -> reverse the edges now outdegree of node becomes the indegree and take the node with indegree zero is terminal node = safe node and apply same topo to get all terminal node(safe node)  
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
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