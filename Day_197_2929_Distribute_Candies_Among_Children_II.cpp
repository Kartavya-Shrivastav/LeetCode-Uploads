#include<bits/stdc++.h>
using namespace std;

// This code defines a function to calculate the number of ways to distribute candies among children
// such that no child receives more than a specified limit of candies.

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long res = 0;
        for (int i = 0; i <= min(limit, n); i++) {
            if (n - i <= 2 * limit)
                res += min(n - i, limit) - max(0, n - i - limit) + 1;
        }
        return res;
    }
};