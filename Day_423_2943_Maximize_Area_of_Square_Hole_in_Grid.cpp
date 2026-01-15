#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a grid of size n x m with some horizontal and vertical bars placed on it, we need to find the maximum area of a square hole that can be formed in the grid without being obstructed by any bars.
// Approach: We can sort the positions of the horizontal and vertical bars. Then, we can find the maximum consecutive gaps between the bars in both directions. The side length of the largest square hole will be determined by the smaller of these two maximum gaps. Finally, we calculate the area of the square hole by squaring this side length.

// Steps:
// 1. Sort the positions of horizontal and vertical bars.
// 2. Find the maximum consecutive gaps between the horizontal bars.
// 3. Find the maximum consecutive gaps between the vertical bars.
// 4. The side length of the largest square hole is the minimum of the two maximum gaps.
// 5. Calculate the area of the square hole by squaring the side length.

// Time Complexity: O(n log n + m log m), where n and m are the number of horizontal and vertical bars respectively, due to sorting.
// Space Complexity: O(1), as we are using only a constant amount of extra space.

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        auto maxSpan = [](vector<int>& bars) {
            int res = 1, streak = 1;
            for (int i = 1; i < bars.size(); i++) {
                if (bars[i] - bars[i - 1] == 1) streak++;
                else streak = 1;
                res = max(res, streak);
            }
            return ++res;
        };

        int s = min(maxSpan(hBars), maxSpan(vBars));
        return s * s;
    }
};