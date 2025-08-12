#include <bits/stdc++.h>
using namespace std;

// Problem: Compute range products of powers of two with modular arithmetic
// Approach: Use properties of powers of two and modular arithmetic to efficiently compute products

// Steps:
// 1. Identify the powers of two present in the binary representation of n.
// 2. Precompute the cumulative products of these powers.
// 3. For each query, compute the product of the specified range using precomputed values and modular inverses.
// 4. Use modular arithmetic to handle large numbers and avoid overflow.
// 5. The function uses a helper function for modular multiplication and another for computing modular inverses using Fermat's Little Theorem.
// 6. The maximum power of two considered is based on the constraints of the problem, ensuring efficient computation.

// Time Complexity: O(log n) for identifying powers of two, O(1) for each query after precomputation
// Space Complexity: O(log n) for storing powers and their inverses

#include <vector>
using namespace std;
static const int MOD = 1'000'000'007;

class Solution {
public:
    int numberOfWays(int n, int x) {
        // collect powers i^x <= n
        vector<int> powers;
        for (int i = 1; ; ++i) {
            long long p = 1;
            for (int k = 0; k < x; ++k) p *= i;
            if (p > n) break;
            powers.push_back((int)p);
        }

        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        for (int p : powers) {
            for (int s = n; s >= p; --s) {
                dp[s] = (dp[s] + dp[s - p]) % MOD;
            }
        }
        return (int)dp[n];
    }
};