#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of points, find the number of valid pairs (p1, p2) such that p1 is to the left and above p2.
// Approach: Sort the points and use a nested loop to count valid pairs.

// Steps:
// 1. Sort the points by x-coordinate (ascending) and y-coordinate (descending).
// 2. Iterate through each point as a potential "upper-left" corner.
// 3. For each "upper-left" point, find all valid "bottom-right" points that are to the right and below it.
// 4. Count the valid pairs.
// 5. Return the total count of valid pairs.

// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        // Step 1: Sort points by x ascending, then by y descending
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) return a[1] > b[1]; // y descending
            return a[0] < b[0];                   // x ascending
        });

        int pairCount = 0;
        int n = points.size();

        // Step 2: Iterate through all points as potential "upper-left" points
        for (int i = 0; i < n; i++) {
            int upperY = points[i][1];       // y-coordinate of upper-left point
            int lowerYLimit = INT_MIN;       // equivalent to Integer.MIN_VALUE

            // Step 3: Check subsequent points as potential "bottom-right" points
            for (int j = i + 1; j < n; j++) {
                int currentY = points[j][1];

                // Valid pair if currentY is below upperY and above previous lowerYLimit
                if (currentY <= upperY && currentY > lowerYLimit) {
                    pairCount++;
                    lowerYLimit = currentY;

                    // Once we reach the same y as upperY, no more valid points possible
                    if (currentY == upperY) break;
                }
            }
        }

        return pairCount;
    }
};

