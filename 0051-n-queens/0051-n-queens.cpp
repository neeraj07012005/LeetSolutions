class Solution {
public:
    vector<vector<string>> ans;

    bool safe(int row, int col, vector<string>& board) {

        // Check column
        for (int i = row - 1; i >= 0; i--) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        int i = row - 1;
        int j = col - 1;

        while (i >= 0 && j >= 0) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j--;
        }

        // Check upper-right diagonal
        i = row - 1;
        j = col + 1;

        while (i >= 0 && j < board.size()) {
            if (board[i][j] == 'Q')
                return false;

            i--;
            j++;
        }

        return true;
    }

    void solve(int row, vector<string>& board) {

        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int col = 0; col < board.size(); col++) {

            if (safe(row, col, board)) {

                board[row][col] = 'Q';

                solve(row + 1, board);

                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, board);

        return ans;
    }
};