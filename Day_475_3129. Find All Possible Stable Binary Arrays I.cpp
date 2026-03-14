#include <bits/stdc++.h>
using namespace std;

/*
Problems: Find the number of stable binary arrays of length zero + one with exactly zero 0s and one 1s, where no more than limit consecutive elements are the same.
Approach:
1. We need to count the number of ways to arrange zero 0s and one 1s such that no more than limit consecutive elements are the same.
2. We can use combinatorial mathematics to count the arrangements. We will define a function F(N, K, L) that counts the number of ways to arrange K elements in N positions with no more than L consecutive elements being the same.
3. We will precompute factorials and inverse factorials to efficiently calculate combinations C(n, k).
4. We will iterate over possible values of K (the number of 1s) and calculate the number of arrangements for both 0s and 1s using the function F, and sum up the results to get the final answer.   
5. The final answer will be taken modulo 10^9 + 7 to handle large numbers.

// Time Complexity: O(maxN^2) due to the nested loops in the function F and the precomputation of factorials.
// Space Complexity: O(maxN) for storing factorials and inverse factorials.
*/

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        long long MOD = 1000000007;
        int maxN = zero + one;
        
        std::vector<long long> fact(maxN + 1, 0);
        std::vector<long long> invFact(maxN + 1, 0);
        
        fact[0] = 1;
        invFact[0] = 1;
        for (int i = 1; i <= maxN; i++) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }
        
        auto power = [&](long long baseVal, long long exp) {
            long long res = 1;
            baseVal %= MOD;
            while (exp > 0) {
                if (exp & 1) res = (res * baseVal) % MOD;
                baseVal = (baseVal * baseVal) % MOD;
                exp >>= 1;
            }
            return res;
        };
        
        invFact[maxN] = power(fact[maxN], MOD - 2);
        for (int i = maxN - 1; i >= 1; i--) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
        
        auto C = [&](int n, int k) -> long long {
            if (k < 0 || k > n) return 0;
            return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
        };
        
        auto F = [&](int N, int K, int L) -> long long {
            if (K <= 0 || K > N) return 0;
            long long ans = 0;
            int maxJ = (N - K) / L;
            for (int j = 0; j <= maxJ; j++) {
                long long term = C(K, j) * C(N - j * L - 1, K - 1) % MOD;
                if (j & 1) {
                    ans = (ans - term + MOD) % MOD;
                } else {
                    ans = (ans + term) % MOD;
                }
            }
            return ans;
        };

        int maxK = std::min(zero, one + 1);
        std::vector<long long> fOne(maxK + 2, 0);
        for (int k = 1; k <= maxK + 1; k++) {
            fOne[k] = F(one, k, limit);
        }
        
        long long ans = 0;
        for (int k = 1; k <= maxK; k++) {
            long long fz = F(zero, k, limit);
            if (fz == 0) continue;
            long long fo = (fOne[k - 1] + 2 * fOne[k] + fOne[k + 1]) % MOD;
            ans = (ans + fz * fo) % MOD;
        }
        
        return static_cast<int>(ans);
    }
};