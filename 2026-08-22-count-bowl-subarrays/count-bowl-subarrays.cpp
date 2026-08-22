class Solution {
    vector<int>nge(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
    vector<int>pge(vector<int>&nums){
        int n=nums.size();
        vector<int>ans(n);
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.empty()){
ans[i]=-1;
            }
            else{
                ans[i]=st.top();
            }
            st.push(nums[i]);
        }
        return ans;
    }
public:
    long long bowlSubarrays(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        vector<int>right=nge(nums);
        vector<int>left=pge(nums);

        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=-1 ){
                count++;
            }
        }
        return count;


        
    }
};