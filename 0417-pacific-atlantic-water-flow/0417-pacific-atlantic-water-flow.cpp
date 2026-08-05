class Solution {
public:

    vector<vector<int>> ans;

    bool pacific = false;
    bool atlantic = false;

    void dfs(int row, int col,
             vector<vector<bool>> &visited,
             vector<vector<int>> &grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }

        if (visited[row][col])
            return;

        if (row == 0 || col == 0) {
            pacific = true;
        }

        if (row == rows - 1 || col == cols - 1) {
            atlantic = true;
        }

        visited[row][col] = true;

        // left 
        if (col + 1 < cols &&
            grid[row][col] >= grid[row][col + 1] &&
            !visited[row][col + 1]) {

            dfs(row, col + 1, visited, grid);
        }

        // up
        if (row - 1 >= 0 &&
            grid[row][col] >= grid[row - 1][col] &&
            !visited[row - 1][col]) {

            dfs(row - 1, col, visited, grid);
        }

        // down
        if (row + 1 < rows &&
            grid[row][col] >= grid[row + 1][col] &&
            !visited[row + 1][col]) {

            dfs(row + 1, col, visited, grid);
        }

        // right 
        if (col - 1 >= 0 &&
            grid[row][col] >= grid[row][col - 1] &&
            !visited[row][col - 1]) {

            dfs(row, col - 1, visited, grid);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int rows = heights.size();
        int cols = heights[0].size();

        for (int i = 0; i < rows; i++) {

            for (int j = 0; j < cols; j++) {

                vector<vector<bool>> visited(
                    rows, vector<bool>(cols, false));

                pacific = false;
                atlantic = false;

                dfs(i, j, visited, heights);

                if (pacific && atlantic) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};