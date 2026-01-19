#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a 2D matrix 'mat' and an integer 'threshold', find the maximum side length of a square sub-matrix such that the sum of its elements is less than or equal to 'threshold'.
// Approach: We will use prefix sums to efficiently calculate the sum of any square sub-matrix in constant time. We will then check all possible square sizes starting from the largest down to 1 to find the maximum valid side length.

// Steps:
// 1. Precompute the prefix sums for the matrix.
// 2. Iterate over all possible square sizes from the largest to the smallest.
// 3. For each size, check all possible positions of the square in the matrix.
// 4. Calculate the sum of the square using the prefix sums.
// 5. If the sum is less than or equal to the threshold, return the current size as the maximum side length.

// Time Complexity: O(min(m, n)^3), where m and n are the dimensions of the matrix, as we check all possible squares.
// Space Complexity: O(m * n), for storing the prefix sums.

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int m = mat.size(), n = mat[0].size();

        vector<vector<int>> pref(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j] =
                    mat[i-1][j-1]
                  + pref[i-1][j]
                  + pref[i][j-1]
                  - pref[i-1][j-1];
            }
        }

        int maxSide = min(m, n);

        while (maxSide > 0) {
            for (int i = 0; i + maxSide <= m; i++) {
                for (int j = 0; j + maxSide <= n; j++) {
                    int sum =
                        pref[i+maxSide][j+maxSide]
                      - pref[i][j+maxSide]
                      - pref[i+maxSide][j]
                      + pref[i][j];
                    if (sum <= threshold) return maxSide;
                }
            }
            maxSide--;
        }
        return 0;
    }
};