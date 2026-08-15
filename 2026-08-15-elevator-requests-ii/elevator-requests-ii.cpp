class Solution {
    typedef long long ll;
public:
    long long elevatorRequests(int n, int start, vector<int>& nums) {
        vector<ll>left;
        vector<ll>right;
        for(int i=0;i<(int)nums.size();i++){
            if(nums[i]<start)left.push_back(start-nums[i]);
            else if(nums[i]>start){
                right.push_back(nums[i]-start);
                
            }
        }
        sort(begin(left),end(left));
        sort(begin(right),end(right));
        int p=left.size();
        int q=right.size();
        vector<int>l(p+1,0),r(q+1,0);
        for(int i=1;i<=p;i++){
            l[i]=left[i-1];
        }
        for(int j=1;j<=q;j++){
            r[j]=right[j-1];
        }

        const ll t=LLONG_MAX/2;
        vector<vector<ll>>timeleft(p+1,vector<ll>(q+1,t));
        vector<vector<ll>>penaltyleft(p+1,vector<ll>(q+1,t));
        vector<vector<ll>>timeright(p+1,vector<ll>(q+1,t));
        vector<vector<ll>>penaltyright(p+1,vector<ll>(q+1,t));

        timeleft[0][0]=0;
        timeright[0][0]=0;
        penaltyleft[0][0]=0;
        penaltyright[0][0]=0;

        for(int i=0;i<=p;i++){
            for(int j=0;j<=q;j++){
                if(i==0 &&j==0) continue;

                if(i>=1){
                    ll bt=-1;
                    ll bp=t;
                    ll bscore=t;
                    ll k=(p+q)-i-j;
                    if(timeleft[i-1][j]<t){
                        ll s=timeleft[i-1][j]+(l[i]-l[i-1]);
                        ll pen=penaltyleft[i-1][j]+s;
                        ll score=pen+k*s;
                        if(score<bscore){
                            bscore=score;
                            bp=pen;
                            bt=s;
                        }
                    }
                    if(timeright[i-1][j]<t){
                            ll s=timeright[i-1][j]+(l[i]+r[j]);
                            ll pen=penaltyright[i-1][j]+s;
                        ll score=pen+k*s;
                            if(score<bscore){
                                bscore=score;
                                bp=pen;
                                bt=s;
                            }
                        }
                        timeleft[i][j]=bt;
                        penaltyleft[i][j]=bp;
                    }
                
                if(j>=1){
                    ll bt=-1;
                    ll bp=t;
                    ll bscore=t;
                    ll k=(p+q)-i-j;
                    if(timeright[i][j-1]<t){
                        ll s=timeright[i][j-1]+(r[j]-r[j-1]);
                        ll pen=penaltyright[i][j-1]+s;
                        ll score=pen+k*s;
                        
                        if(score<bscore){
                            bscore=score;
                            bp=pen;
                            bt=s;
                        }
                    }
                    if(timeleft[i][j-1]<t){
                        ll s=timeleft[i][j-1]+(r[j]+l[i]);
                        ll pen=penaltyleft[i][j-1]+s;
                        ll score=pen+k*s;
                        if(score<bscore){
                            bscore=score;
                            bp=pen;
                            bt=s;
                        }
                    }
                        timeright[i][j]=bt;
                        penaltyright[i][j]=bp;
                    
                }
            }
        }
        return min(penaltyleft[p][q],penaltyright[p][q]);
        
    }
};