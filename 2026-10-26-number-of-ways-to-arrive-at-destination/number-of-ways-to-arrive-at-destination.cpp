class Solution {
    int mod=1e9+7;
    typedef long long ll;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<ll>ways(n,0);
        ways[0]=1;
        vector<ll>dist(n,LLONG_MAX);
        dist[0]=0;
        priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto it=pq.top();
            ll dis=it.first;
            int node=it.second;
            pq.pop();
            if(dis>dist[node]) continue;
            for(auto x:adj[node]){
                int adjNode=x.first;
                int edw=x.second;
                if(dis+edw<dist[adjNode]){
                    dist[adjNode]=dis+edw;
                    pq.push({dis+edw,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(dis+edw==dist[adjNode]){
                     ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }
            }
        }
        return (ways[n-1])%mod;
        
    }
};