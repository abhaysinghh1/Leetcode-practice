class Solution {
    typedef long long ll;
public:
    vector<int> countTasks(vector<int>& tasks, vector<int>& shifts) {
         int n=tasks.size();
        int m=shifts.size();
        vector<int>res(m);

        vector<ll>s(n+1,0);
        for(int i=0;i<n;i++){
            s[i+1]=s[i]+tasks[i];
            
        }
        ll tot=s[n];
         ll tc=0;
        for(int j=0;j<m;j++){
            tc+=shifts[j];
            if(tc>=tot){
                res[j]=0;
                tc=0;
                
            }
            else{
                int task_idx=upper_bound(s.begin(),s.end(),tc)-s.begin()-1;
                res[j]=n-task_idx;
            }
            
        }
        return res;
    }
};