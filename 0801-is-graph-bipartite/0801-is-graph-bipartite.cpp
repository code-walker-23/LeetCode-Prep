class Solution {
public:

    void dfs(int src,vector<vector<int>>&adj,vector<int>&vis,unordered_set<int> &A,unordered_set<int> &B,bool &isBipartite){
        vis[src] = 1;

        for(int nbrs : adj[src]){
            if(A.find(src) != A.end()){
                if(A.find(nbrs) != A.end()){
                    isBipartite = false;
                    return;
                }else{
                    B.insert(nbrs);
                    if(!vis[nbrs]){
                        dfs(nbrs,adj,vis,A,B,isBipartite);
                    }
                }
            }else{
                if(B.find(nbrs) != B.end()){
                    isBipartite = false;
                    return;
                }else{
                    A.insert(nbrs);
                    if(!vis[nbrs]){
                        dfs(nbrs,adj,vis,A,B,isBipartite);
                    }
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n,0);
        bool isBipartite = true;
        unordered_set<int> A,B;
        
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                A.insert(i);
                dfs(i,graph,vis,A,B,isBipartite);
                if(!isBipartite)return false;
            }
        }

        return true;
    }
};