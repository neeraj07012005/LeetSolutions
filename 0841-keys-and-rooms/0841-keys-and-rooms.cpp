class Solution {
private:
    void dfs(int node, vector<vector<int>>& room, vector<bool>&visited){
        visited[node]=true;
        for(int neighbour:room[node]){
            if(!visited[neighbour]){
                dfs(neighbour , room, visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(),false);
        dfs(0, rooms, visited);
        for(int i =0; i < visited.size();i++){
            if(visited[i]==false){
                return false;
            }
        }
        return true;
    }
};