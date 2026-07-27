#include <vector>

using namespace std;

class Solution {
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= 1000000007;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % 1000000007;
            base = (base * base) % 1000000007;
            exp /= 2;
        }
        return res;
    }

    long long modInverse(long long n) {
        return power(n, 1000000007 - 2);
    }

    long long nCr(int n, int r, const vector<long long>& fact, const vector<long long>& invFact) {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % 1000000007 * invFact[n - r] % 1000000007;
    }

public:
    int countValidSequences(int n, int k) {
        if (k > n) return 0;
        
        int MOD = 1000000007;
        vector<long long> fact(n + 1, 1);
        vector<long long> invFact(n + 1, 1);
        
        for (int i = 1; i <= n; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        invFact[n] = modInverse(fact[n]);
        for (int i = n - 1; i >= 0; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }

        long long total = nCr(n - 1, k - 1, fact, invFact);
        long long allOdd = 0;

        if ((n - k) % 2 == 0 && n >= k) {
            int m = (n - k) / 2;
            allOdd = nCr(m + k - 1, k - 1, fact, invFact);
        }

        long long ans = (total - allOdd + MOD) % MOD;
        return ans;
    }
};