class Solution {
    
    
public:
    int sumOfPrimesInRange(int n) {
        
        int p=n;
        string s=to_string(p);
        reverse(s.begin(),s.end());
        p=stoi(s);
        int large;
        int sum=0;
        int mini=min(p,n);
        int maxi=max(p,n);
        vector<bool>prime(maxi+1,true);
        prime[0]=false;
        prime[1]=false;
        for(int i=2;i*i<=maxi;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=maxi;j+=i){
                    prime[j]=false;
                }
            }
            
        }
      
        for(int i=mini;i<=maxi;i++){
            if(prime[i]==true){
                sum+=i;
            }
        }
        
        return sum;
    }
};