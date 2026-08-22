class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(st.empty() ||st.top()<=nums[i]){
st.push(nums[i]);

            }
        }
        return st.size();
    }
};