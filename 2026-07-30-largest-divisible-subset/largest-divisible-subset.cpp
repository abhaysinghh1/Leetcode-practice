class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> t(n, 1);
        vector<int> prev(n, -1);

        int maxi = 1;
        int maxi_index = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {

                    if (t[j] + 1 >t[i]) {
                        t[i] = t[j] + 1;
                        prev[i] = j;
                    }
                    if (t[i] > maxi) {
                        maxi = t[i];
                        maxi_index = i;
                    }
                }
            }
        }

        vector<int> ans;
        while(maxi_index!=-1){
            ans.push_back(nums[maxi_index]);
            maxi_index=prev[maxi_index];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};