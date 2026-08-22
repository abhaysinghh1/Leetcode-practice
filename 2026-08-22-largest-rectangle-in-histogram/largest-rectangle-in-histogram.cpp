class Solution {
    vector<int>nse(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i]){
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
    vector<int>pse(vector<int>& nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i]=-1;

            }
            else{
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        vector<int>left=pse(nums);
        vector<int>right=nse(nums);
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,(right[i]-left[i]-1)*nums[i]);
        }
        return ans;
        
    }
};