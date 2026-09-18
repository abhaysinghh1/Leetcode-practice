class Solution {
    typedef long long ll;
    ll digit_sum(ll n){
        ll ans=0;
        while(n>0){
            ans+=n%10;
            n/=10;
        }
        return ans;

    }
public:
    long long makeIntegerBeautiful(long long n, int target) {
         if(n<=target) return 0;
         ll original=n;
         ll base =10 ;
         while(digit_sum(n)>target){
            ll rem=n%base;
            if(rem!=0){
                n+=(base-rem);
            
            }
            
            base*=10;
         }

         return n-original;



        
    }
};