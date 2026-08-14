class Solution {
    int n;
    int solve(vector<int>& nums,int i,int ans ){
        if(i>=n) {
           
            return ans;
        }
        //take
        int include=solve(nums,i+1,ans^nums[i]);
        int exclude=solve(nums,i+1,ans);
        return include+exclude;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        n=nums.size();
        int res=solve(nums,0,0);
        return res;
    }
};