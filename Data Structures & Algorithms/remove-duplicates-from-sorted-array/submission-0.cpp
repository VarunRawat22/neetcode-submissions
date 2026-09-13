class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
        }
        for(int i=0; i<ans.size(); i++) {
            nums[i] = ans[i];
        }
        return ans.size();

    }
};