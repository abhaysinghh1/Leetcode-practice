class Solution {
public:
    int findMin(vector<int>& arr) {
        int n=arr.size();
         int lo=0;
         int hi=n-1;
         int mini=INT_MAX;
         while(lo<=hi){
             int mid=lo+(hi-lo)/2;
             
             if(arr[mid]>=arr[lo]){
                 mini=min(mini,arr[lo]);
                 lo=mid+1;
             }
             else{
                 mini=min(mini,arr[mid]);
                 hi=mid-1;
             }
             
             
             
         }
         return mini;
    }
};