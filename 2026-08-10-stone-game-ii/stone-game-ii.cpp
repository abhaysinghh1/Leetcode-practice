class Solution {
    int n;
    int t[2][101][101];

    int solve( int person,int i ,int m,vector<int>& piles){
        if(i>=n) return 0;
        if(t[person][i][m]!=-1) return t[person][i][m];
        int res=(person==1)?-1:INT_MAX;
        int stone=0;
        for( int x=1;x<=min(2*m,n-i);x++){
            stone+=piles[i+x-1];
            if(person==1){
               res=max(res,stone+solve(0,i+x,max(x,m),piles));
            }
            else{
                res=min(res,solve(1,i+x,max(x,m),piles));
            }

        }
        return t[person][i][m]=res;
    }
public:
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(t,-1,sizeof(t));
        int ans=solve(1,0,1,piles);
        return ans;
        
        
    }
};