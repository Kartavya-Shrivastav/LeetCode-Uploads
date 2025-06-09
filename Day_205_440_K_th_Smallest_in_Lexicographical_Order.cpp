#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Main function to find the k-th smallest number in lexicographical order
    static int findKthNumber(int n, int K) {
        return solve(0, n, K);
    }

    // Recursive helper function to traverse the lexicographical tree
    static int solve(long long current, long long n, long long k) {
        // If k is 0, we've found the k-th number
        if (k == 0)
            return (int)(current / 10);

        // Try all possible next digits
        for (long long i = max(current, 1LL); i < current + 10; ++i) {
            long long count = numOfChildren(i, i + 1, n); // Count numbers in the subtree
            if (count >= k)
                // If the k-th number is in this subtree, go deeper
                return solve(i * 10, n, k - 1);
            k -= count; // Otherwise, skip this subtree
        }
        return -1; // Should not reach here
    }

    // Counts how many numbers are in the subtree rooted at 'current' and less than or equal to n
    static long long numOfChildren(long long current, long long neighbour, long long n) {
        if (neighbour > n) {
            if (current > n) return 0;
            return n - current + 1;
        }
        // Count numbers in the current range and recursively in deeper levels
        return neighbour - current + numOfChildren(current * 10, neighbour * 10, n);
    }
};