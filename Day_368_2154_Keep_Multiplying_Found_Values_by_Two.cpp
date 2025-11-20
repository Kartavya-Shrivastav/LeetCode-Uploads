#include <bits/stdc++.h>
using namespace std;

// Problem: Keep Multiplying Found Values by Two
// Approach: Bit Manipulation to Track Powers of k

// Steps:
// 1. Iterate through the input array `nums`.
// 2. For each number, check if it is divisible by `k`. If it is, divide it by `k` repeatedly until it is no longer divisible.
// 3. Check if the resulting number is a power of two using the condition `(n & (n - 1)) == 0`.
// 4. Use a bitmask `bits` to track which powers of two have been found.
// 5. Finally, return the smallest power of `k` that has not been found by multiplying `k` with the least significant bit set in `bits`.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findFinalValue(vector<int>& nums, int k) {
        int bits = 0;
        for (auto& n : nums) {
            if (n % k != 0) continue;
            n /= k;
            if ((n & (n - 1)) == 0)
                bits |= n;
        }
        bits++;
        return k * (bits & -bits);
    }
};