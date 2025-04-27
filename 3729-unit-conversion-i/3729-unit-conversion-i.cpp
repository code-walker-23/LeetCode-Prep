class Solution {
public:
    const int M = 1e9 + 7;
    vector<vector<pair<int,int>>> g;
    vector<int> res;

    void dfs(int src) {
        for (auto& [nbr, x] : g[src]) {
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
