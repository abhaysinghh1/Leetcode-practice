class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n=tokens.size();
        if(n==0 )return 0;
        sort(tokens.begin(),tokens.end());
        int ans=0;
        int score=0;
         
        if(tokens[0]>power) return 0;
       
       int left=0;
       int right=n-1;
       while(left<=right){
        if(power>=tokens[left]){
            score++;
            power-=tokens[left];
            left++;
            ans=max(ans,score);
        }
        else if(score>0){
            
            score--;
            power+=tokens[right];
            right--;
        }
        else {
            break;
        }
       }
       return ans;
    }
};