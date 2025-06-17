#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of arrays of length n with m distinct integers such that there are exactly k pairs of adjacent elements that are equal.
// Approach: Use combinatorial counting and modular arithmetic to calculate the number of valid arrays.

// Steps:
// 1. Calculate the number of ways to choose k pairs of adjacent elements from n-1 positions.
// 2. For each pair, choose one of the m integers.
// 3. For the remaining n - (k + 1) positions, choose from  
//    the remaining m - 1 integers (since one integer is already used for the pairs).


const int MOD = 1e9 + 7;

class Solution {
public:
    // Computes modular inverse of a under modulo mod using Fermat's little theorem
    long long modInverse(long long a, long long mod){
        long long res = 1;
        long long power = mod - 2;

        while (power){
            if (power & 1)
                res = res * a % mod;
            a = a * a % mod;
            power >>= 1;
        }

        return res;
    }

    // Computes n choose r (nCr) modulo MOD
    int nCr(int n, int r){
        if (r > n) return 0;
        if (r == 0 || r == n) return 1;

        long long res = 1;

        // Calculate nCr using multiplicative formula and modular inverse
        for (int i = 1; i <= r; i++){
            res = res * (n - r + i) % MOD;
            res = res * modInverse(i, MOD) % MOD;
        }

        return (int)res;
    }

    // Computes a^b modulo MOD using binary exponentiation
    long long bin_expo(long long a, long long b)
    {
        long long result = 1;
        while (b) {
            if (b & 1)
                result = (result * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return result;
    }

    // Main function to count the number of good arrays
    int countGoodArrays(int n, int m, int k) {
        // Number of ways to fill n-(k+1) positions with m-1 choices (adjacent pairs fixed)
        int formula = (m * 1ll * bin_expo(m-1, n-(k+1))) % MOD;

        // Multiply by the number of ways to choose k pairs from n-1 positions
        int updated_formula = (formula * 1ll * nCr(n-1, k)) % MOD; 

        return updated_formula;
    }
};