class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
       int ans=0;
       while(n>0){
        if(n==1){
            ans+=10;
            n--;
        }
        else if(n>1){
            int temp=1;
            int i=n-1;
            int j=9;
            while(i>0){
                temp=temp*(j);
                j--;
                i--;


            }
            temp*=9;
            ans+=temp;
            n--;
        }
       }
    return ans;
    }
};