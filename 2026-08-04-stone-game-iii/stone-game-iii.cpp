class Solution {
    int solve(vector<int>& stoneValue, int i ,vector<int>&t) {
        if (i >= stoneValue.size())
            return 0;

  if(t[i]!=-1) return t[i];
        int diff = INT_MIN;


        diff = max(diff, stoneValue[i] -solve(stoneValue, i + 1,t));

        if (i + 1 < stoneValue.size()) {
            diff = max(diff, stoneValue[i] + stoneValue[i + 1] -
                                 solve(stoneValue, i + 2,t));
        }  if (i + 2 < stoneValue.size()) {
            diff = max(diff, stoneValue[i] + stoneValue[i + 1] +
                                 stoneValue[i + 2] - solve(stoneValue, i + 3,t));
        }
        return t[i]=diff;
    }

public:
    string stoneGameIII(vector<int>& stoneValue) {
         int n = stoneValue.size(); 
         vector<int>t(n,-1);
         int diff=solve(stoneValue,0,t);
         if(diff>0) return "Alice";
         else if(diff==0) return "Tie";
         else return "Bob";
         }
};