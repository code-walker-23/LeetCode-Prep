class Solution {
    void dfs(int src,int[] vis, ArrayList<ArrayList<Integer>>adj){
        vis[src] = 1;

        for(int nbr : adj.get(src)){
            if(vis[nbr] == 0){
                dfs(nbr,vis,adj);
            }
        }
    }
    public int findCircleNum(int[][] isConnected) {
        int n = isConnected.length;
        ArrayList<ArrayList<Integer>>adj = new ArrayList<>();

        for(int i = 0; i < n; i++){
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj.get(i).add(j);
                    adj.get(i).add(j);
                }
            }
            
        }

        int[] vis = new int[n];
        int provinces = 0;

        for(int i = 0; i < n; i++){
            if(vis[i] == 0){
                provinces++;
                dfs(i,vis,adj);
            }
        }

        return provinces;
    }
}