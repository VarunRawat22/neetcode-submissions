class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++) {

            // same starting element dobara use nahi karna
            if(i > 0 && nums[i] == nums[i-1])
                continue;

            int l = i + 1;
            int r = n - 1;

            while(l < r) {

                long long sum = (long long)nums[i] + nums[l] + nums[r];

                if(sum == 0) {

                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    r--;

                    // duplicate left values skip
                    while(l < r && nums[l] == nums[l-1])
                        l++;

                    // duplicate right values skip
                    while(l < r && nums[r] == nums[r+1])
                        r--;
                }

                else if(sum < 0) {
                    l++;
                }

                else {
                    r--;
                }
            }
        }

        return ans;
    }
};