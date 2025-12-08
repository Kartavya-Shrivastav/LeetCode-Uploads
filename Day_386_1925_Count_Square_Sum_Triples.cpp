#include <bits/stdc++.h>
using namespace std;

// Problem: Count Square Sum Triples
// Approach: Number Theory with Euclid's Formula

// Steps:
// 1. Use Euclid's formula to generate primitive Pythagorean triples (a, b, c) where a = u^2 - v^2, b = 2uv, c = u^2 + v^2.
// 2. Iterate over possible values of u and v to find all primitive triples such that c <= n.
// 3. For each primitive triple, count its multiples that fit within the limit n.   

// Time Complexity: O(n log n) in the worst case due to the nested loops and gcd calculations
// Space Complexity: O(1)

class Solution {
public:
    int countTriples(int n) {
        int res = 0;
        for (int u = 2; u <= sqrt(n); u++) {
            for (int v = 1; v < u; v++) {
                if (~(u - v) & 1 || gcd(u, v) != 1) continue;
                int c = u * u + v * v;
                if (c > n) continue;
                res += (n / c) << 1;
            }
        }
        return res;
    }
};