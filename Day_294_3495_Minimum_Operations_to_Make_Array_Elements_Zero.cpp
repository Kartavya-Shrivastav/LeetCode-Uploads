#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of queries where each query consists of two integers [l, r], determine the minimum number of operations required to make all elements in the range [l, r] zero.
//          In each operation, you can select a power of two and subtract it from any element in

// Approach: For each query, calculate the total number of operations required based on the binary representation of numbers in the range.
//           Use properties of binary numbers to determine the maximum number of operations needed for any single number

// Steps:
// 1. For each query, initialize variables to track the total operations and maximum operations for any single number.
// 2. Loop through possible bit lengths (1 to 31) to cover the range of numbers.
// 3. For each bit length, determine the range of numbers that can be represented with that many bits.
// 4. Calculate the count of numbers in the query range that fall within this bit length.
// 5. For each number in this range, calculate the number of operations required based on its bit length.
// 6. Update the total operations and maximum operations accordingly.
// 7. The result for each query is the maximum of the total operations divided by 2 (rounded up) and the maximum operations for any single number.

// Time Complexity: O(Q * 31) where Q is the number of queries, due to the nested loops.
// Space Complexity: O(1)

class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for (auto &q : queries) {
            int l = q[0], r = q[1];
            long long S = 0;
            int dMax = 0;

            for (int k = 1; k <= 31; k++) {
                long long low = 1LL << (k - 1);
                long long high = (1LL << k) - 1;
                if (low > r) break;
                long long a = max((long long)l, low);
                long long b = min((long long)r, high);
                if (a > b) continue;
                long long cnt = b - a + 1;
                int stepsForK = (k + 1) / 2;
                S += cnt * stepsForK;
                dMax = max(dMax, stepsForK);
            }

            long long ops = max((long long)dMax, (S + 1) / 2);
            ans += ops;
        }
        return ans;
    }
};