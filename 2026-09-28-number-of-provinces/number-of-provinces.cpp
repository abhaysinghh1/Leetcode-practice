class Solution {
    void dfs(int i,unordered_map<int,vector<int>>&mpp,vector<int>&vis){
        vis[i]=1;
        for(auto it:mpp[i]){
            if(vis[it]==0){
                dfs(it,mpp,vis);
            }
        }
        return;
    }
public:
    int findCircleNum(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>mpp;
         int n=mat.size();
         for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1&& i!=j){
                    mpp[i].push_back(j);

                }
            }
         }
         vector<int>vis(n,0);
         int cnt=0;
         for(int i=0;i<n;i++){
            if(vis[i]==0){
                cnt++;
                dfs(i,mpp,vis);

            }
         }
         return cnt;
        
    }
};