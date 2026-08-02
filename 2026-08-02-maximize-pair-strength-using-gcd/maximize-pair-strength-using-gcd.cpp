class Solution {
    typedef long long ll;
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        ll maxi=INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){

                ll div=gcd(nums[i],nums[j]);
                ll sdiv=div*div;
                ll temp=(1LL*nums[i]*nums[j])/sdiv;
                maxi=max(maxi,temp);
            }
        }
        return maxi;
        
    }
};