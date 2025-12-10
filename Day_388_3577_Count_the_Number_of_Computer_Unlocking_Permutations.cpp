#include <bits/stdc++.h>
using namespace std;

// Problem: Count the Number of Computer Unlocking Permutations
// Approach: Factorial Calculation with Validity Check

// Steps:
// 1. Check if all complexities after the first are greater than the first complexity.
// 2. If any complexity is less than or equal to the first, return 0 as no valid permutations exist.
// 3. Calculate the factorial of (n-2) where n is the number of computers, since the first computer is fixed and the last can be any of the remaining.
// 4. Return the factorial result modulo 10^9 + 7.

// Time Complexity: O(n) where n is the number of computers.
// Space Complexity: O(1) for the factorial calculation.

class Solution {
public:
    static const int MOD = 1000000007;

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();
        int first = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= first) return 0;
        }

        long long fact = 1;
        for (int i = 2; i < n; i++) {
            fact = (fact * i) % MOD;
        }

        return (int)fact;
    }
};