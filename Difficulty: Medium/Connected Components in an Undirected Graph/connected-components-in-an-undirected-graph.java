
class Solution {
    void dfs(int src,int[] vis,ArrayList<ArrayList<Integer>> adj,ArrayList<Integer>comp){
        vis[src] = 1;
        comp.add(src);
        
        for(int nbr : adj.get(src)){
            if(vis[nbr] == 0){
                dfs(nbr,vis,adj,comp);
            }
        }
        
    }
    public ArrayList<ArrayList<Integer>> getComponents(int V, int[][] edges) {
        // code here
        // convert the adj matrix to list for better time comp
        int n = V;
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();
        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }
        
         for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        ArrayList<ArrayList<Integer>> comp = new ArrayList<>();
        int []vis = new int[n];
        
        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                ArrayList newComp = new ArrayList<>();
                dfs(i,vis,adj,newComp);
                comp.add(newComp);
            }
        }
        
        return comp;
    }
}