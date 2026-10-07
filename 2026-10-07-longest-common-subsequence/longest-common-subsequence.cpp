class Solution {

    int solve( int n,int m,string& X, string& Y,vector<vector<int>>&t){
       for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0||j==0) t[i][j]=0;
            else if(X[i-1]==Y[j-1]){
            t[i][j]=1+t[i-1][j-1];
           }
           else{
            t[i][j]=max(t[i][j-1],t[i-1][j]);
           }
        }
       }
       return t[n][m]; 
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(n,m,text1,text2,dp);
        
    }
};