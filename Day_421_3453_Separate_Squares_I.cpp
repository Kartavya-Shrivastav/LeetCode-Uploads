#include <bits/stdc++.h>
using namespace std;

// Problem: Separate Squares I
// Approach: Binary search on the horizontal line position to balance areas above and below.

// Steps:
// 1. Calculate the total area of all squares and determine the vertical bounds (low and high).
// 2. Set the target area as half of the total area.
// 3. Perform binary search for 100 iterations:
//    - Calculate the mid-point between low and high.
//    - Compute the area of squares below the mid-point.
//    - If the area below is less than the target area, move the low bound up; otherwise, move the high bound down.
// 4. Return the high bound as the position of the horizontal line that separates the squares.

// Time Complexity: O(n * log(A)), where n is the number of squares and A is the range of y-coordinates.
// Space Complexity: O(1), as we are using only a constant amount of extra space

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double totalArea = 0;
        double low = 2e9;
        double high = 0;

        for (auto& s : squares) {
            double y = s[1];
            double l = s[2];
            totalArea += l * l;
            low = min(low, y);
            high = max(high, y + l);
        }

        double targetArea = totalArea / 2.0;

        for (int i = 0; i < 100; ++i) {
            double mid = low + (high - low) / 2.0;
            double currentArea = 0;

            for (auto& s : squares) {
                double y = s[1];
                double l = s[2];
                double h_below = max(0.0, min(l, mid - y));
                currentArea += h_below * l;
            }

            if (currentArea < targetArea) {
                low = mid;
            } else {
                high = mid;
            }
        }

        return high;
    }
};