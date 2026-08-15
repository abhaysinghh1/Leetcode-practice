class Solution {
    void solve(int col,int n,vector<vector<string>>&ans,vector<string>&boards,vector<int>&curr,vector<int>&ud, vector<int>&ld){
        if(col==n){
            ans.push_back(boards);
            return;
        }
        for(int row=0;row<n;row++){
            if(curr[row]==0 && ud[n-1+col-row]==0 && ld[col+row]==0){
                boards[row][col]='Q';
                curr[row]=1;
                ud[(n-1)+col-row]=1;
                ld[col+row]=1;
                solve(col+1,n,ans,boards,curr,ud,ld);
                boards[row][col]='.';
                curr[row]=0;
                ud[n-1+col-row]=0;
                ld[col+row]=0;

            }
        }
        return;
    }
public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>boards(n);
        string s(n,'.');
        vector<int>curr(n,0);
        vector<int>ud(2*n-1,0);
        vector<int>ld(2*n-1,0);
        for(int i=0;i<n;i++){
            boards[i]=s;
        }
solve(0,n,ans,boards,curr,ud,ld);
return ans;

    }
};