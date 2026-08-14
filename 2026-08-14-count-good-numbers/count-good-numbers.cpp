class Solution {
    int mod = 1e9 + 7;
    long long power(long long a, long long n) {
        long long ans = 1;
        while (n > 0) {
            if (n & 1) {
                ans = ans * a % mod;
            }
            a = a * a % mod;
            n = n >> 1;
        }
        return ans;
    }

public:
    int countGoodNumbers(long long n) {
        long long  first = (n + 1) / 2;
        long long  sec = n / 2;
        return power(5, first) * power(4, sec) % mod;
    }
};