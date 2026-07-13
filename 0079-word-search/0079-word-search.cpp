class Solution {
private:
    bool solve(vector<vector<char>>& board, string &word, int r, int c, int i) {

        // Base Case
        // All characters matched
        if (i == word.size())
            return true;

        // Boundary check
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size())
            return false;

        // Already visited
        if (board[r][c] == '#')
            return false;

        // Current character doesn't match
        if (board[r][c] != word[i])
            return false;

        // Mark visited
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore all 4 directions
        bool found =
            solve(board, word, r + 1, c, i + 1) ||   // Down
            solve(board, word, r - 1, c, i + 1) ||   // Up
            solve(board, word, r, c + 1, i + 1) ||   // Right
            solve(board, word, r, c - 1, i + 1);     // Left

        // Backtrack
        board[r][c] = temp;

        return found;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {

        int rows = board.size();
        int cols = board[0].size();

        // Try every cell as the starting point
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                // Start DFS only if first character matches
                if (board[i][j] == word[0]) {
                    if (solve(board, word, i, j, 0))
                        return true;
                }
            }
        }

        return false;
    }
};