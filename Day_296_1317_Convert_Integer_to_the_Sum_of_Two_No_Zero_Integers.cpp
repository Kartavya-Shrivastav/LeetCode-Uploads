#include <bits/stdc++.h>
using namespace std;

// Problem: Given an integer n, return two integers such that they add up to n and neither contains the digit zero.
// Approach: Use a brute-force approach to check pairs of integers that sum to n and verify that neither contains the digit zero.

// Steps:
// 1. Define a helper function to check if a number contains the digit zero.
// 2. Loop through integers from 1 to n-1, checking each pair (i, n-i).
// 3. If both integers in the pair do not contain the digit zero, return them.
// 4. Return an empty vector if no such pair is found (though the problem guarantees a solution).

// Time Complexity: O(n * d) where n is the input integer and d is the number of digits in n, as we may check up to n pairs and each check takes O(d).
// Space Complexity: O(1) for storing the result pair.


class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        auto check = [](int x) {
            while (x > 0) {
                if (x % 10 == 0) return false;
                x /= 10;
            }
            return true;
        };
        for (int i = 1; i < n; ++i) {
            int j = n - i;
            if (check(i) && check(j)) {
                return {i, j};
            }
        }
        return {};
    }
};