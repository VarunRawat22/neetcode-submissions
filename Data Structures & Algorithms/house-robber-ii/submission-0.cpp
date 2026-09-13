class Solution {
    int f(int ind, int start, vector<int>& nums, vector<int>& dp) {
        if (ind < start) return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + f(ind - 2, start, nums, dp);
        int notPick = f(ind - 1, start, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: 0 to n-2
        vector<int> dp1(n, -1);
        int first = f(n - 2, 0, nums, dp1);

        // Case 2: 1 to n-1
        vector<int> dp2(n, -1);
        int second = f(n - 1, 1, nums, dp2);

        return max(first, second);
    }
};