class Solution {
private:
    vector<int> dp;

    // solve(i) = Maximum money that can be robbed from houses 0...i
    int solve(vector<int>& nums, int i) {

        // Base Cases
        if (i == 0)
            return nums[0];

        if (i == 1)
            return max(nums[0], nums[1]);

        // Already computed?
        if (dp[i] != -1)
            return dp[i];

        // Choice 1: Skip current house
        int skip = solve(nums, i - 1);

        // Choice 2: Rob current house
        int rob = solve(nums, i - 2) + nums[i];

        // Store and return the best choice
        dp[i] = max(skip, rob);

        return dp[i];
    }

public:
    int rob(vector<int>& nums) {

        // Edge case
        if (nums.size() == 1)
            return nums[0];

        dp.resize(nums.size(), -1);

        return solve(nums, nums.size() - 1);
    }
};