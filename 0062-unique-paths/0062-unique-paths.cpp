class Solution {
    int m, n;
    vector<vector<int>> dp;

    int solve(int row, int col) {

        if(row >= m || col >= n)
            return 0;

        if(row == m - 1 && col == n - 1)
            return 1;

        if(dp[row][col] != -1)
            return dp[row][col];

        int right = solve(row, col + 1);
        int down = solve(row + 1, col);

        return dp[row][col] = right + down;
    }

public:
    int uniquePaths(int m, int n) {

        this->m = m;
        this->n = n;

        dp = vector<vector<int>>(m, vector<int>(n, -1));

        return solve(0, 0);
    }
};