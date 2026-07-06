class Solution {
private:
    void solve(int n, int open, int close, string curr, vector<string>& ans) {
        if (open == n && close == n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n) {
            curr.push_back('(');
            solve(n, open + 1, close, curr, ans);
            curr.pop_back();
        }

        // Add ')' if it keeps the string valid
        if (close < open) {
            curr.push_back(')');
            solve(n, open, close + 1, curr, ans);
            curr.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, 0, 0, "", ans);
        return ans;
    }
};