class Solution {
    typedef long long ll;

public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<ll> idx(k, 1);
        vector<ll> num(n + 1);
        num[1] = 1;
        for (int i = 2; i <= n; i++) {
            ll mini = LLONG_MAX;
            for (int j = 0; j < k; j++) {
                ll candi = (ll)num[idx[j]] * primes[j];
                mini = min(mini, candi);
            }
            num[i] = mini;

            for (int j = 0; j < k; j++) {
                if ((ll)num[idx[j]] * primes[j] == mini) {
                    idx[j]++;
                }
            }
        }
        return num[n];
    }
};