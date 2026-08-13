class Solution {
public:
    int timer =1;
    void dfs(int node,int parent,vector<vector<int>> &adj,vector<int> &tin, vector<int> &vis,vector<int> &low,vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;

        for(auto it:adj[node]){
            if(it==parent) continue;
            if(vis[it]==0){
                dfs(it,node,adj,tin,vis,low,bridges);
                low[node]=min(low[node],low[it]);
                if(tin[node]<low[it]){
                    bridges.push_back({node,it});
                }
            }else{
                low[node]=min(low[node],low[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        vector<int> vis(n,0),tin(n),low(n);
        for(int i=0;i<connections.size();i++){
            int node = connections[i][0];
            int adjnode = connections[i][1];
            adj[node].push_back(adjnode);
            adj[adjnode].push_back(node);
        }
        vector<vector<int>> bridges;


        for(int i=0;i<n;i++){
            if(vis[i]==0)dfs(i,-1,adj,tin,vis,low,bridges);
        }

        return bridges;

    }
};