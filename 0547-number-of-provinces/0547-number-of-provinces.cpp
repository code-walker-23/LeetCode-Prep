class Solution {
public:
    void multiSourceBfs(int src,vector<vector<int>> &isConnected,vector<bool> &vis){
        queue<int>q;
        q.push(src);
        vis[src] = true;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();

            for(int i = 0; i < isConnected.size(); i++){
                if(isConnected[front][i] == 1 && !vis[i]){
                    q.push(i);
                    vis[i] = true;
                }
            }
        }

    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool>vis(n,false);
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                multiSourceBfs(i,isConnected,vis);
                count++;
            }
        }

        return count;
    }
};