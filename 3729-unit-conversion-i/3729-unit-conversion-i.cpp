class Solution {
public:
// 1. Every node is reachable form 0th node.
// 2. Every node has unique path from 0th node (a node is not reachable from two or more nodes). 
    const int M = 1e9 + 7;
    vector<vector<pair<int,int>>> g;
    vector<int> res;

    void dfs(int src) {
        for (auto& [nbr, x] : g[src]) {
            // used 1LL otherwise we can not write like this 1e9*1e9 make it ll and then take modulo
            res[nbr] = (res[src]*1LL*x) % M;
            dfs(nbr);
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size() + 1;
        g.resize(n);
        res.assign(n, 0);
        res[0] = 1; 

        for (auto& conv : conversions) {
            int src = conv[0], tgt = conv[1];
            int factor = conv[2];
            g[src].push_back({tgt, factor});
        }

        dfs(0);
        return res;
    }
};
