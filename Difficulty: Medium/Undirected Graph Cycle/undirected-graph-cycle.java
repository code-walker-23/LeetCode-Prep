class Solution {
    public boolean dfs(int src,int parent,int[] vis,ArrayList<ArrayList<Integer>>adj){
        vis[src] = 1;
        
        for(int nbr : adj.get(src)){
            if(vis[nbr] == 0){
                boolean isExist = dfs(nbr,src,vis,adj);
                if(isExist)return true;
            }else if(nbr != parent)return true;
        }
        
        return false;
    }
    public boolean isCycle(int V, int[][] edges) {
        // Code here
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>(V);
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        // taking both connected or not-connected
        int[] vis = new int[V];
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                if(dfs(i,-1,vis,adj))return true;
            }
        }
        
        return false;
        
    }
}