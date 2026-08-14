class Solution {
    void solve(int ind,int k,int n,vector<int>&ds,vector<vector<int>>&ans,vector<int>&nums){
        if(k==0 ){
            if(n==0){
                ans.push_back(ds);
                
            }
            return;
        }
        for(int i=ind;i<=9;i++){
            if(nums[i]>n) break;
            ds.push_back(nums[i]);

            solve(i+1,k-1,n-nums[i],ds,ans,nums);
            ds.pop_back();

        }
        return;

    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1;i<=9;i++){
            nums.push_back(i);
        }
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,k,n,ds,ans,nums);
        return ans;
        
    }
};