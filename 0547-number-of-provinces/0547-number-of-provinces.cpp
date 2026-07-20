class Solution {
private:

    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, visited);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int n = isConnected.size();
        int c = 0;

        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);

        // Build adjacency list
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        // Count provinces
        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                c++;
                dfs(i, adj, visited);
            }

        }

        return c;
    }
};