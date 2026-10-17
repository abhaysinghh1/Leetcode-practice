class Solution {
    vector<int>delrow={-1,1,0,0};
    vector<int>delcol={0,0,-1,1};

    bool is_safe(int row,int col,int m,int n){
        if((row>=0 && row<n) &&(col>=0 &&col<m)) return true;
        return false;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,1));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                q.push({{i,j},1});
            }
        }


        int dist=1;
       while(!q.empty()){
        auto node=q.front();
        q.pop();
        int row=node.first.first;
        int col=node.first.second;
        int temp=node.second;
        //agr kahin se longer path mil chuka hai to isko kyun dalna hai
        if(temp<dp[row][col])continue;

        dist=max(dist,temp);
        for(int i=0;i<4;i++){
            int nrow=row+delrow[i];
            int ncol=col+delcol[i];
            if(is_safe(nrow,ncol,m,n) && matrix[row][col]<matrix[nrow][ncol]){
                if (temp + 1 > dp[nrow][ncol]) {
                        dp[nrow][ncol] = temp + 1;
                        q.push({{nrow, ncol}, temp + 1});
                    }
            }
        }

       }
       return dist;
    
    }
};