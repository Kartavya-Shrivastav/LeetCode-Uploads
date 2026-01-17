#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given two arrays representing the bottom-left and top-right coordinates of rectangles, find the largest area of a square that can fit inside the intersection of any two rectangles.
// Approach: We will iterate through all pairs of rectangles, calculate their intersection, and determine the largest square that can fit within that intersection.

// Steps:
// 1. Iterate through all pairs of rectangles using nested loops.
// 2. For each pair, calculate the coordinates of the intersection rectangle.
// 3. Determine the width and height of the intersection.
// 4. The side length of the largest square that can fit in the intersection is the minimum of the width and height.
// 5. Keep track of the maximum side length found and compute the area at the end.

// Time Complexity: O(n^2), where n is the number of rectangles, as we check all pairs.
// Space Complexity: O(1), as we are using only a constant amount of extra space


class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        long long maxSide = 0;
        int n = bottomLeft.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // Calculate the intersection boundaries
                long long x1 = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long y1 = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long x2 = min(topRight[i][0], topRight[j][0]);
                long long y2 = min(topRight[i][1], topRight[j][1]);

                // Calculate width and height of the intersection
                long long width = x2 - x1;
                long long height = y2 - y1;

                // Check if they actually intersect
                if (width > 0 && height > 0) {
                    long long currentSide = min(width, height);
                    maxSide = max(maxSide, currentSide);
                }
            }
        }

        return maxSide * maxSide;
    }
};