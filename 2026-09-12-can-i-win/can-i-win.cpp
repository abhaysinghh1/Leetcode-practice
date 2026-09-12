class Solution {
int dp[1 << 20];

    bool solve(int mask, int curr, int maxnum, int target) {
        if (dp[mask] != -1)
            return dp[mask];
        for (int i = 1; i <= maxnum; i++){
            if(mask & (1<<(i-1))) continue;

            if(curr+i>=target) return dp[mask]=true;
            int newmask=mask|(1<<(i-1));

            bool canOppWin=solve(newmask,curr+i,maxnum,target);
            if(!canOppWin) return dp[mask]=true;
        }
        return  dp[mask]=false;
    }

public:
    bool canIWin(int mci, int dt) {
        if (dt <= 0)
            return true;
        if ((mci * (mci + 1)) / 2 < dt)
            return false;

        memset(dp, -1, sizeof(dp));
         return solve(0,0,mci,dt);

    }
};