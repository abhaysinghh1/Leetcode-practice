class Solution {
    vector<int>nse(vector<int>& arr){
         int n=arr.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=n;
            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
       

    }
public:
    vector<int> finalPrices(vector<int>& nums) {
         int n=nums.size();
         vector<int>right=nse(nums);
         vector<int>ans;
         for(int i=0;i<n;i++){
            int temp;
            if(right[i]!=n){
                 temp=nums[i]-nums[right[i]];
            }
            else{
                 temp=nums[i];
            }
            ans.push_back(temp);
         }
         return ans;
        
    }
};