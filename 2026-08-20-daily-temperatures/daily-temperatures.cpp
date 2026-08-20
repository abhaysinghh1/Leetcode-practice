class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n=nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                nge[i]=0;
            }
            else{
                nge[i]=st.top()-i;
            }
            st.push(i);
        }

    return nge;
    }
};