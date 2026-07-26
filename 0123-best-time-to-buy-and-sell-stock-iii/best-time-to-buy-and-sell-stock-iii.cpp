class Solution {
     int dp[100001][2][3];
    int solve (vector<int>& prices,int i,int buy ,int n,int curr){
        if(i==n || curr>2) return  0;
        int profit=0;
     if(dp[i][buy][curr]!=-1) return dp[i][buy][curr];
        if(buy){
   profit=max(-prices[i]+solve(prices,i+1,0,n,curr),solve(prices,i+1,1,n,curr));
        }
        else{
            profit=max(+prices[i]+solve(prices,i+1,1,n,curr+1),solve(prices,i+1,0,n,curr));
        }
         return  dp[i][buy][curr]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
         int n=prices.size();
         memset(dp,-1,sizeof(dp));
         int ans=solve(prices,0,1,n,1);
         return ans;
    }
};

