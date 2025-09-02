#include <bits/stdc++.h>
using namespace std;

// Problem: Find the number of ways to place people in pairs
// Approach: Sort the points and use a two-pointer technique to count valid pairs

// Steps:
// 1. Sort the points based on their x-coordinates (and y-coordinates for ties)
// 2. Use two pointers to find valid pairs of points
// 3. Count the number of valid pairs
// 4. Return the result

// Time Complexity: O(n log n) for sorting, O(n^2) for the two-pointer search
// Space Complexity: O(1) for the two-pointer search

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &a, const auto &b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

        int res = 0, n = points.size();
        for (int i = 0; i < n; i++)
        {
            int b = points[i][1], last = -1;
            for (int j = i + 1; j < n; j++)
            {
                int a = points[j][1];
                if (a <= b && a > last)
                {
                    last = a;
                    ++res;
                }
            }
        }

        return res;
    }
};