class Solution {
    const int mod=1e9+7;
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for( auto it:nums){
            pq.push(it);
        }
        while(k--){
            int mini=pq.top();
            pq.pop();
            int n_mini=mini+1;
            pq.push(n_mini);
        }

        long long  res=1;
         while(!pq.empty()){
            int n=pq.top();
            pq.pop();
            res=((res%mod)*(n%mod))%mod;
         }

         return res;
        
    }
};