class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c,
             vector<vector<bool>>& visited) {

        // Boundary check
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
            return;

        // Water or already visited
        if (grid[r][c] == '0' || visited[r][c])
            return;

        // Mark current cell as visited
        visited[r][c] = true;

        // Explore all 4 directions
        dfs(grid, r + 1, c, visited); // Down
        dfs(grid, r - 1, c, visited); // Up
        dfs(grid, r, c + 1, visited); // Right
        dfs(grid, r, c - 1, visited); // Left
    }

    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int islands = 0;

        // Traverse every cell
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Found a new island
                if (grid[i][j] == '1' && !visited[i][j]) {
                    islands++;
                    dfs(grid, i, j, visited);
                }
            }
        }

        return islands;
    }
};