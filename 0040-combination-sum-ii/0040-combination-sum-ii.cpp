class Solution {
private:
    void solve(vector<int>& candidates, int i,
               vector<int>& curr,
               vector<vector<int>>& ans,
               int target) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        // Include current element
        curr.push_back(candidates[i]);
        solve(candidates, i + 1, curr, ans, target - candidates[i]);
        curr.pop_back();

        // Skip all duplicates for the exclude branch
        int next = i;
        while (next + 1 < candidates.size() &&
               candidates[next] == candidates[next + 1]) {
            next++;
        }

        // Exclude current element
        solve(candidates, next + 1, curr, ans, target);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(candidates, 0, curr, ans, target);

        return ans;
    }
};