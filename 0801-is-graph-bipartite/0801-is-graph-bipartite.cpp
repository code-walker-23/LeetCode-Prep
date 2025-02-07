class Solution {
public:

    bool dfs(int src,int col,vector<vector<int>>&adj,vector<int>&color){
        color[src] = col;

        for(auto nbrs : adj[src]){
            if(color[nbrs] == -1){
                if(dfs(nbrs,!col,adj,color) == false)return false;
            }
            if(color[nbrs] == col)return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);

        for(int i = 0; i < n; i++){
            if(color[i] == -1){
                if(dfs(i,0,graph,color) == false)return false;
            }
        }
        return true;
    }

};