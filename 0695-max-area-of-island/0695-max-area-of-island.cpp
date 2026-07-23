class Solution {

private:
    int dfs(int row, int col,
            vector<vector<int>>& grid,
            vector<vector<bool>>& visited) {

        int rows = grid.size();
        int cols = grid[0].size();

        // Boundary check
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return 0;
        }

        // Water
        if (grid[row][col] == 0) {
            return 0;
        }

        // Already visited
        if (visited[row][col]) {
            return 0;
        }

        // Mark visited
        visited[row][col] = true;

        return 1
             + dfs(row - 1, col, grid, visited)
             + dfs(row + 1, col, grid, visited)
             + dfs(row, col - 1, grid, visited)
             + dfs(row, col + 1, grid, visited);
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int area = 0;

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == 1 && !visited[i][j]) {

                    area = max(area, dfs(i, j, grid, visited));

                }

            }

        }

        return area;
    }
};