class Solution {
    typedef long long ll;
public:
    int kthDigit(long long k) {
        if(k<=9) return (int)k;
        k-=9;
        long long d=1;
        while(true){
            ll bs=10*(d+1);
            ll powD=1;
            for(int i=0;i<d-1;i++){
                powD*=10;
            }
            ll numB=9*powD;
            ll gt=numB*bs;
            if(k<=gt){
                ll idx=k-1;
                ll blockOffset=idx/bs;
                ll rem=idx%bs;
                ll b=powD+blockOffset;

                ll numI=rem/(d+1);
                ll digitI=rem%(d+1);
                ll num;
                if(b%2==0)num=10*b+numI;
                else num=10*b+(9-numI);

                string s=to_string(num);
                return s[digitI]-'0';
                
            }
            else{
                k-=gt;
                d++;
            }
        }
    }
};