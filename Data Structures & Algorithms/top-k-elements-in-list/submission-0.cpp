class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        // Step 1: frequency count
        for (int x : nums) {
            mp[x]++;
        }

        int n = nums.size();

        // bucket[freq] = elements
        vector<vector<int>> bucket(n + 1);

        for (auto it : mp) {
            int element = it.first;
            int freq = it.second;

            bucket[freq].push_back(element);
        }

        vector<int> ans;

        // highest frequency se start
        for (int freq = n; freq >= 1; freq--) {

            for (int element : bucket[freq]) {

                ans.push_back(element);

                if (ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};