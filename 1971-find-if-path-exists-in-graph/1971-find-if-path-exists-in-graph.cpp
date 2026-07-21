class Solution {

private:
    void dfs(int node,vector<vector<int>> &adj,vector<bool> &visited){
        visited[node]=true;
        for(int neighbour:adj[node]){
            if(!visited[neighbour]){
                dfs(neighbour, adj , visited);
            }
        }
        
    }

public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n,false);
        
        dfs(source, adj,visited);
        return (visited[destination]);
    }
};