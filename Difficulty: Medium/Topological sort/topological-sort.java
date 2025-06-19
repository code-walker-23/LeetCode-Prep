class Solution {
    // public static void dfs(int src,int[] vis,ArrayList<ArrayList<Integer>> adj,ArrayList<Integer> topo){
    //     vis[src] = 1;
        
    //     for(int nbr : adj.get(src)){
    //         if(vis[nbr] == 0){
    //             dfs(nbr,vis,adj,topo);
    //         }
    //     }
        
    //     // after going to the deep push the src
    //     topo.add(src);
    // }
    
    // We will be using Kahn's algorithm
    public static ArrayList<Integer> topoSort(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
        for(int i = 0; i < V; i++){
            adj.add(new ArrayList<>());
        }
        
        int[] indegree = new int[V];
        
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj.get(u).add(v);
            indegree[v]++;
        }

        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < V; i++)if(indegree[i] == 0)q.add(i);
        ArrayList<Integer> topo = new ArrayList<>();
        
        while(!q.isEmpty()){
            int front = q.remove();
            topo.add(front);
            
            for(int nbr : adj.get(front)){
                indegree[nbr]--;
                if(indegree[nbr] == 0)q.add(nbr);
            }
        }        
        
        return topo;
        // ArrayList<Integer> topo = new ArrayList<>();
        // int[] vis = new int[V];
        
        // for(int i = 0; i < V; i++){
        //     if(vis[i] == 0){
        //         dfs(i,vis,adj,topo);
        //     }
        // }
        
        // Collections.reverse(topo);
        // return topo;
        
        
    }
}