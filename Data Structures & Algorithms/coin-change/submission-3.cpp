
class Solution {
    int f(int ind, vector<int>& coins, int amount,
          vector<vector<int>>& dp) {

        if (ind == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return INT_MAX;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int notTake = f(ind - 1, coins, amount, dp);

        int take = INT_MAX;
        if (coins[ind] <= amount) {
            int res = f(ind, coins, amount - coins[ind], dp);
            if (res != INT_MAX)
                take = 1 + res;
        }

        return dp[ind][amount] = min(take, notTake);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(
            n, vector<int>(amount + 1, -1)
        );

        int ans = f(n - 1, coins, amount, dp);

        return ans == INT_MAX ? -1 : ans;
    }
};
