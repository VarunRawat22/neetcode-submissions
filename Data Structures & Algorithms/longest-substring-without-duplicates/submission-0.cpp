class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        unordered_map<char, int> mp;
        int maxi = 0;

        while (r < n) {

            mp[s[r]]++;

            // duplicate mila
            while (mp[s[r]] > 1) {
                mp[s[l]]--;
                l++;
            }

            int len = r - l + 1;
            maxi = max(maxi, len);

            r++;
        }

        return maxi;
    }
};