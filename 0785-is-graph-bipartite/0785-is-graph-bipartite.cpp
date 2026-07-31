class Solution {
private:
    bool dfs(int node,vector<vector<int>>&adj , vector<int>&colored , vector<bool> &visited){
        visited[node]=true;
        for(auto neigh:adj[node]){
            
            if(!visited[neigh]){
                if(colored[node]==1){
                    colored[neigh]=2;
                    if(!dfs(neigh,adj,colored,visited)){
                        return false;
                    };
                }
                else{
                    colored[neigh]=1;
                    if(!dfs(neigh, adj, colored, visited)){
                        return false;
                    };
                }
            

            }
            if(colored[node]==colored[neigh]){
                return false;
            }

        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size() , false);
        vector<int> color(graph.size(),-1);
        color[0]=1;
        for(int i = 0 ; i < graph.size();i++){
            if(!visited[i]){
                color[i]=1;
                if(!dfs(i , graph , color , visited)){
                    return false;
                }
            }
        }
        return true;
    }
};