class Solution {
    public boolean dfs(int src,int[] vis, int[] pathVis,ArrayList<ArrayList<Integer>> adj){
        vis[src] = 1;
        pathVis[src] = 1;
        
        for(int nbr : adj.get(src)){
            if(vis[nbr] == 0){
                if(dfs(nbr,vis,pathVis,adj))return true;
            }else if(pathVis[nbr] == 1)return true;
        }
        
        pathVis[src] = 0;
        return false;
    }
    public boolean isCyclic(int V, int[][] edges) {
        // code here
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj.get(u).add(v);
        }
        
        int[] vis = new int[V];
        int[] pathVis = new int[V];
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                if(dfs(i,vis,pathVis,adj))return true;
            }
        }
        
        return false;
    }
}