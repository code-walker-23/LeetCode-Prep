class Solution {
public:
    bool dfs(int src,vector<int>&vis,vector<vector<int>>&adj){
        vis[src] = 2;

        for(int nbr : adj[src]){
            if(!vis[nbr]){
                if(dfs(nbr,vis,adj))return true;
            }else if(vis[nbr] == 2)return true;
        }

        vis[src] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int vertices = numCourses;
        int edges = prerequisites.size();
        vector<vector<int>>adj(vertices);

        for(int i = 0; i < edges; i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<int>vis(vertices,0);
        for(int i = 0; i < vertices; i++){
            if(!vis[i]){
                if(dfs(i,vis,adj))return false;
            }
        }

        return true;
    }
};