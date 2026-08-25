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
public:
    int maximalRectangle(vector<vector<char>>& arr) {
        // yahan par ye dhyan rakhna hai ki arr or matrix char ki hai  na ki int ki;
        int ans=0;
        int n=arr.size();
        int m=arr[0].size();
        vector<vector<int>>p(n,vector<int>(m));
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
               
                if(arr[j][i] == '0') {
                    sum = 0;
                }
                else {
                    sum++;
                }

                p[j][i] = sum;
            }
        }

        for(int i=0;i<n;i++){
 ans=max(ans,largestRectangleArea(p[i]));
        }
        return ans;
        
    }
};