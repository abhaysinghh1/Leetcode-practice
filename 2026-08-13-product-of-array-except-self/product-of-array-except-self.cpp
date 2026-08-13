class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>front(n);
        vector<int>back(n);
        int prev=1;
       
        back[n-1]=1;
        for(int i=0;i<n;i++){
            front[i]=prev;
            prev*=nums[i];
        }
        prev=1;
        for(int i=n-1;i>=0;i--){
            back[i]=prev;
            prev*=nums[i];
        }
        for(int i=0;i<n;i++){
            nums[i]=back[i]*front[i];
        }
        return  nums;
    }
};