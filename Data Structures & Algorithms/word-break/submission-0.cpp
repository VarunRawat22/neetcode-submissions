
class Solution {
    bool f(int ind, string& s,
           unordered_set<string>& st,
           vector<int>& dp) {

        int n = s.size();

        // Entire string successfully segmented
        if (ind == n) return true;

        if (dp[ind] != -1) return dp[ind];

        string temp = "";

        for (int i = ind; i < n; i++) {

            temp += s[i];

            if (st.count(temp)) {
                if (f(i + 1, s, st, dp)) {
                    return dp[ind] = true;
                }
            }
        }

        return dp[ind] = false;
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();

        unordered_set<string> st(
            wordDict.begin(), wordDict.end()
        );

        vector<int> dp(n, -1);

        return f(0, s, st, dp);
    }
};
