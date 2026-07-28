class Solution {
private:
    void dfs(int node, vector<vector<int>>& graph, vector<int> &path, vector<vector<int>>&ans){
        path.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        
        for(int neighbour:graph[node]){
            
            dfs(neighbour, graph , path, ans);
        }
        path.pop_back();
    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(0,graph, path,ans);
        return ans;

    }
};