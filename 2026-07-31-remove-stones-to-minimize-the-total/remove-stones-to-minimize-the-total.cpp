class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
         int n=piles.size();
          priority_queue<int>pq;
          for(int i=0;i<n;i++){
            pq.push(piles[i]);
          }

          while(k>0){
            int t=pq.top();
            pq.pop();
            pq.push(t-t/2);
            k--;
          }

          int ans=0;
          while(!pq.empty()){
            ans+=pq.top();
            pq.pop();
          }
          return ans;
    }
};