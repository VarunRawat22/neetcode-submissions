class Solution {
    int f(int ind,vector<int>& nums,vector<int>& dp){
        int n=nums.size();

        if(ind==0) return nums[0];
        if(ind==1) return max(nums[0],nums[1]);
        if(dp[ind]!=-1) return dp[ind];
        
        int np=INT_MIN;
        if(ind>1){
            np=0+f(ind-1,nums,dp);
        }
        int pick=INT_MIN;
        if(ind>=2){
            pick= nums[ind]+f(ind-2,nums,dp);
        }
        return dp[ind]=max(np,pick);

    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        return f(n-1,nums,dp);
        
    }
};
