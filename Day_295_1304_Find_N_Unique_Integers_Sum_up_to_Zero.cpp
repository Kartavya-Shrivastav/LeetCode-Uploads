#include <bits/stdc++.h>
using namespace std;

// Problem: Given an integer n, return any array containing n unique integers such that they add up to 0.
// Approach: Use a simple mathematical approach to generate pairs of positive and negative integers.

// Steps:
// 1. Initialize an empty vector to store the result.
// 2. Loop from 1 to n/2, adding both i and -i to the result vector.
// 3. If n is odd, add 0 to the result vector.
// 4. Return the result vector.

// Time Complexity: O(n) where n is the input integer, as we are generating n integers.
// Space Complexity: O(n) for storing the result vector.

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        for (int i = 1; i <= n / 2; ++i) {
            ans.push_back(i);
            ans.push_back(-i);
        }
        if (n % 2 == 1) {
            ans.push_back(0);
        }
        return ans;
    }
};