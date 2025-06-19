class Solution {
    public static void dfs(int src,int[] vis,ArrayList<ArrayList<Integer>> adj,ArrayList<Integer> topo){
        vis[src] = 1;
        
        for(int nbr : adj.get(src)){
            if(vis[nbr] == 0){
                dfs(nbr,vis,adj,topo);
            }
        }
        
        // after going to the deep push the src
        topo.add(src);
    }
    
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj.get(u).add(v);
        }
        
        ArrayList<Integer> topo = new ArrayList<>();
        int[] vis = new int[V];
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                dfs(i,vis,adj,topo);
            }
        }
        
        Collections.reverse(topo);
        
        return topo;
        
    }
}