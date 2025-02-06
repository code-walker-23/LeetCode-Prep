class Solution {
public:

    void dfs(int src, vector<vector<int>>& adj, vector<int>& vis, unordered_set<int>& A, unordered_set<int>& B, bool& notBipartite) {
        vis[src] = 1;

        for (int nbr : adj[src]) {
            if (A.count(src)) {  
                if (A.count(nbr)) { 
                    notBipartite = true;
                    return;
                }
                if (!vis[nbr]) {  
                    B.insert(nbr);
                    dfs(nbr, adj, vis, A, B, notBipartite);
                    if (notBipartite) return;
                }
            } else { 
                if (B.count(nbr)) {
                    notBipartite = true;
                    return;
                }
                if (!vis[nbr]) {
                    A.insert(nbr); 
                    dfs(nbr, adj, vis, A, B, notBipartite);
                    if (notBipartite) return;
                }
            }
        }
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, 0);
        bool notBipartite = false;
        unordered_set<int> A, B;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                A.insert(i);
                dfs(i, graph, vis, A, B, notBipartite);
                if (notBipartite) return false;
            }
        }

        return true; 
    }

};