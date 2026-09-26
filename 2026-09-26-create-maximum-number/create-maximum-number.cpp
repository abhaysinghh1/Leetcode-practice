class Solution {
    vector<int> getMax(vector<int>&arr, int k) {
        vector<int> st;
        int rem = arr.size() - k;
        for (auto it : arr) {
            while (!st.empty() && st.back() < it && rem > 0) {
                st.pop_back();
                rem--;
            }
            st.push_back(it);
        }
        st.resize(k);
        return st;
    }

    bool greatersuffix(vector<int>& a, int i, vector<int>& b, int j) {
        while (i < a.size() && j < b.size() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (j == b.size())
            return true;
        if (i == a.size())
            return false;
        return a[i] > b[j];
    }

    vector<int> merge(vector<int>& a, vector<int>& b) {
        vector<int> ans;
        int i = 0;
        int j = 0;

        while (i < a.size() || j < b.size()) {
            if (i == a.size()) {
                ans.push_back(b[j++]);

            } else if (j == b.size()) {
                ans.push_back(a[i++]);
            } else if (a[i] > b[j]) {
                ans.push_back(a[i++]);
            } else if (a[i] < b[j]) {
                ans.push_back(b[j++]);
            } else {
                if (greatersuffix(a, i, b, j)) {
                    ans.push_back(a[i++]);
                } else {
                    ans.push_back(b[j++]);
                }
            }
        }
        return ans;
    }

public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> ans;
        int st = max(0, k - (int)nums2.size());
        int en = min(k, (int)nums1.size());
        // ye for loop iss liye hai ki ham kis arr se kitna value le rahein hai

        for (int i = st; i <= en; i++) {
            int take2 = k - i;
            vector<int> a = getMax(nums1, i);
            vector<int> b = getMax(nums2, take2);
            vector<int> candi = merge(a, b);
            if (candi > ans) {
                ans = candi;
            }
        }
        return ans;
    }
};