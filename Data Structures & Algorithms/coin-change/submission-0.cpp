class Solution {
    int f(int ind, int target, vector<int>& coins,
          vector<vector<int>>& dp) {

        if(target == 0)
            return 0;

        if(ind == 0) {
            if(target % coins[0] == 0)
                return target / coins[0];

            return 1e9;
        }

        if(dp[ind][target] != -1)
            return dp[ind][target];

        int NP = f(ind - 1, target, coins, dp);

        int pick = 1e9;

        if(coins[ind] <= target) {
            // same ind because coin can be reused
            pick = 1 + f(ind, target - coins[ind], coins, dp);
        }

        return dp[ind][target] = min(pick, NP);
    }

public:
    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector<vector<int>> dp(
            n,
            vector<int>(amount + 1, -1)
        );

        int ans = f(n - 1, amount, coins, dp);

        return ans >= 1e9 ? -1 : ans;
    }
};