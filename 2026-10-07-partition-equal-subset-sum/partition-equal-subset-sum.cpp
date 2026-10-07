class Solution {
    bool solve(int i,int target,vector<int>& nums,vector<vector<int>>&dp){
        int n=nums.size();
        if(i==n ) return target==0;
        if(target==0) return true;
        if(dp[i][target]!=-1) return dp[i][target];
        int take;
        
        if(nums[i]<=target){
             take=solve(i+1,target-nums[i],nums,dp);
        }
        int not_take=solve(i+1,target,nums,dp);
        return dp[i][target]=(take|| not_take);

    }
public:
    bool canPartition(vector<int>& nums) {
         int sum=accumulate(nums.begin(),nums.end(),0);
         int n=nums.size();
         if(sum%2==1) return false;
         int target=sum/2;
         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));

         return solve(0,target,nums,dp);

    }
};