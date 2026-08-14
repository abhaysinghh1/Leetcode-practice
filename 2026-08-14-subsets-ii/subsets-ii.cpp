class Solution {
    void solve(int ind,int len,vector<int>& nums,vector<int>&ds,vector<vector<int>>&ans){
  
    ans.push_back(ds);
    
  
  for(int i=ind;i<len;i++){
    if(i>ind && nums[i]==nums[i-1]){
        continue;
    }
    ds.push_back(nums[i]);
    solve(i+1,len,nums,ds,ans);
    ds.pop_back();
  }
  return;
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,n,nums,ds,ans);
        return ans;
    }
};