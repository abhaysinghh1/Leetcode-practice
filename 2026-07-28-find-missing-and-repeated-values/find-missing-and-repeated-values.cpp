class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<int>hash(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                hash[grid[i][j]]++;
            }
        }
        int missing;
        int dob;
        vector<int>ans;
        for(int i=0;i<=n*n;i++){
            if(hash[i]==0){
               missing=i;
            }
            else if(hash[i]==2){
                dob=i;
            }
        }
        return {dob,missing};
    }
};