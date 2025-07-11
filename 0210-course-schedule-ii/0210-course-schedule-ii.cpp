class Solution {
public:
// // we can merge these two functions as well
//     void dfs(int src,vector<int>&vis,vector<int>&order,vector<vector<int>>&adj){
//         vis[src] = 1;

//         for(auto nbr : adj[src]){
//             if(!vis[nbr]){
//                 dfs(nbr,vis,order,adj);
//             }
//         }

//         order.push_back(src);
//     }

    // bool isCycle(int src,vector<int>&vis,vector<vector<int>>&adj){
    //     vis[src] = 2;

    //     for(auto nbr : adj[src]){
    //         if(!vis[nbr]){
    //             if(isCycle(nbr,vis,adj))return true;
    //         }else if(vis[nbr] == 2)return true;
    //     }

    //     vis[src] = 1;
    //     return false;
    // }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int v = numCourses;
        int e = prerequisites.size();
        vector<vector<int>>adj(v);

        for(int i = 0; i < e; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];

            adj[u].push_back(v);
        }

        // vector<int>cycleVis(v,0);
        // vector<int>order;

        // for(int i = 0; i < v; i++){
        //     if(!cycleVis[i]){
        //         if(isCycle(i,cycleVis,adj))return order;
        //     }
        // }

        // vector<int>vis(v,0);
        // for(int i = 0; i < v; i++){
        //     if(!vis[i]){
        //         dfs(i,vis,order,adj);
        //     }
        // }

        // reverse(order.begin(),order.end());
        // return order;

        vector<int>indegree(v,0);
        vector<int>topoOrder;
        queue<int>q;
        
        for(int i = 0; i < v; i++){
            for(auto nbr : adj[i])indegree[nbr]++;
        }
        for(int i = 0; i < v; i++)if(indegree[i] == 0)q.push(i);
        
        // while is stop without executing all vertices that mean there is a cycle
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoOrder.push_back(node);
            
            for(auto nbr : adj[node]){
                indegree[nbr]--;
                if(indegree[nbr] == 0)q.push(nbr);
            }
        }
        if(topoOrder.size() == v)return topoOrder;
        return {};
    }
};