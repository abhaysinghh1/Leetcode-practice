class Solution {
    bool check(vector<int>& nums, int k,int maxi){
        int cnt=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<=maxi){
                continue;
            }
            else{
                cnt+=1;
               sum=nums[i];
            }
        }
        return cnt>=k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int lo=*max_element(nums.begin(),nums.end());
        int hi=0;
        for(auto it:nums){
            hi+=it;
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(check(nums,k,mid)){
                lo=mid+1;
            }
            else{
               hi=mid-1;
            }
        }
        return lo;
        
    }
};