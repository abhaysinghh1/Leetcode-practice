class Solution {
    vector<int>delrow={-1,1,0,0};
    vector<int>delcol={0,0,-1,1};
    int m,n;

    int  dfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        vis[i][j]=1;
        int ans=1;
        for(int k=0;k<4;k++){
            int nrow=i+delrow[k];
            int ncol=j+delcol[k];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                ans+=dfs(nrow,ncol,grid,vis);
            }
        }
        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
         int res=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                }
                else if(grid[i][j] == 1 && !vis[i][j] ){
                    int area= dfs(i,j,grid,vis);
                    res=max(res,area);

                }
            }
        }

        return res;
        
    }
};