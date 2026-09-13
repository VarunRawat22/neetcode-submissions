class Solution {
    int f(int ind, int target, vector<int>& nums,
          vector<vector<int>>& dp) {

        // Base case
        if (ind == 0) {

            // nums[0] = 0 and target = 0
            // +0 and -0 => 2 ways
            if (target == 0 && nums[0] == 0)
                return 2;

            // target 0 ban sakta hai by not taking
            // ya nums[0] == target hai toh taking
            if (target == 0 || nums[0] == target)
                return 1;

            return 0;
        }

        // already calculated
        if (dp[ind][target] != -1)
            return dp[ind][target];

        // current element nahi lenge
        int notPick = f(ind - 1, target, nums, dp);

        // current element lenge
        int pick = 0;

        if (nums[ind] <= target) {
            pick = f(ind - 1,
                     target - nums[ind],
                     nums,
                     dp);
        }

        return dp[ind][target] = pick + notPick;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {

        int n = nums.size();

        int total = 0;

        for (int x : nums) {
            total += x;
        }

        /*
            P - N = target
            P + N = total

            => 2N = total - target
            => N = (total - target) / 2
        */

        // impossible cases
        if (total - target < 0)
            return 0;

        if ((total - target) % 2 != 0)
            return 0;

        int sum = (total - target) / 2;

        // DP initialized with -1
        vector<vector<int>> dp(
            n,
            vector<int>(sum + 1, -1)
        );

        return f(n - 1, sum, nums, dp);
    }
};