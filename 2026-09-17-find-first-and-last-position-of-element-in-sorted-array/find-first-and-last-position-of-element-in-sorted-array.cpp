class Solution {
    int firstocc(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] >= target) {
               if(nums[mid] == target) {
                    ans = mid; // Track index only if it matches target
                }
                hi = mid - 1;

            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
    int lastocc(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;
        int ans = -1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] <= target) {
                if(nums[mid] == target) {
                    ans = mid; // Track index only if it matches target
                }
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstocc(nums, target);
        int last = lastocc(nums, target);

        return {first, last};
    }
};