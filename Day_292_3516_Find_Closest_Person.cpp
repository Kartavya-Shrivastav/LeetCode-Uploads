#include <bits/stdc++.h>
using namespace std;

// Problem: Given three integers x, y, and z representing the positions of two people and a target location,
//          determine which person is closer to the target location z. If both are equally close, return 0.
// Approach: Calculate the absolute differences between each person's position and the target location,
//           then compare these differences to determine the result.

// Steps:
// 1. Calculate the absolute difference between x and z.
// 2. Calculate the absolute difference between y and z.
// 3. Compare the two differences:
//    - If they are equal, return 0.
//    - If the difference for x is less than that for y, return 1.
//    - Otherwise, return 2.

// Time Complexity: O(1)
// Space Complexity: O(1)


class Solution {
public:
    int findClosest(int x, int y, int z) {
        return abs(x-z)==abs(y-z)?0:2-(abs(x-z)<abs(y-z));
    }
};