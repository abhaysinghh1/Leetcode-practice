class Solution {
    void solve(int i,int n,int k,vector<int>&comb,vector<vector<int>>&ans){
        if(comb.size()==k){
            ans.push_back(comb);
            return ;
        }
        for(int j=i;j<=n;j++){
            comb.push_back(j);
            solve(j+1,n,k,comb,ans);
            comb.pop_back();
        }

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>comb;

        solve(1,n,k,comb,ans);
        return ans;
    }
};