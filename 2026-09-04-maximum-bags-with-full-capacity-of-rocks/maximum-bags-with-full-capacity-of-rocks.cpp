class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int extra) {
        int n=rocks.size();
        vector<int>diff(n);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];


        }
        int cnt=0;
        sort(diff.begin(),diff.end());

 for(int i=0;i<n;i++){
    if(diff[i]<=extra){
        extra-=diff[i];
        cnt++;
    }
 }
 return cnt;
    }
};