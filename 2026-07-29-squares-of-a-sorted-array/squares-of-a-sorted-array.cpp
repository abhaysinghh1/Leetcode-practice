class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
         int n=nums.size();
         vector<int>ans;
         for(auto it:nums){
            ans.push_back(it*it);
         }
         sort(ans.begin(),ans.end());
         return ans;
    }
};