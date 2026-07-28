class Solution {
private:
    int solve(int i, vector<int>& nums, vector<int>& dp) {

        // Base Case
        if (i >= nums.size() - 1)
            return 0;

        // Memoization
        if (dp[i] != -1)
            return dp[i];

        dp[i] = 9999;

        // Try every possible jump
        for (int jump = 1; jump <= nums[i]; jump++) {
            dp[i] = min(dp[i], 1 + solve(i + jump, nums, dp));
        }

        return dp[i];
    }

public:
    int jump(vector<int>& nums) {

        vector<int> dp(nums.size(), -1);

        return solve(0, nums, dp);
    }
};