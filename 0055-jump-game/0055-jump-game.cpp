class Solution {
public:
    bool solve(int i, vector<int>& nums, vector<int>& dp) {

        // Base Case
        if (i >= nums.size() - 1)
            return true;

        // Already Computed
        if (dp[i] != -1)
            return dp[i];

        // Try every possible jump
        for (int jump = 1; jump <= nums[i]; jump++) {
            if (solve(i + jump, nums, dp))
                return dp[i] = true;
        }

        return dp[i] = false;
    }

    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};