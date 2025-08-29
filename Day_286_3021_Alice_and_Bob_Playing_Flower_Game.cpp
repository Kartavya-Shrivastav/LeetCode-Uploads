#include <bits/stdc++.h>
using namespace std;

// Problem: Alice and Bob are playing a game with flowers.
// Approach: We can use a mathematical formula to find the total number of ways to choose 2 flowers from n+m flowers.

// Steps
// 1. Calculate the total number of flowers: total = n + m
// 2. Use the formula for combinations to find the number of ways to choose 2 flowers from total: C(total, 2) = total * (total - 1) / 2
// 3. Return the result

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    long long flowerGame(int n, int m) {
        return 1LL * n * m / 2;
    }
};