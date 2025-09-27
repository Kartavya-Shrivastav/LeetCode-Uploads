#include <bits/stdc++.h>
using namespace std;

// Problem: 611. Valid Triangle Number
// Approach: Sorting and Two-Pointer Technique

// Steps:
// 1. Sort the array of side lengths.
// 2. Iterate through the array, treating each element as the longest side of a potential triangle.
// 3. Use two pointers to find pairs of sides that can form a triangle with the longest side.
// 4. Count the number of valid triangles for each longest side and accumulate the total count.
// 5. Return the total count of valid triangles.

// Time Complexity: O(n^2), where n is the number of sides, due to the nested loops.
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    int triangleNumber(vector<int>& sides) {
        sort(sides.begin(), sides.end());
        int n = sides.size();
        int totalTriangles = 0;

        for (int longest = n - 1; longest >= 2; --longest) {
            int left = 0, right = longest - 1;
            while (left < right) {
                if (sides[left] + sides[right] > sides[longest]) {
                    totalTriangles += (right - left);
                    right--;
                } else {
                    left++;
                }
            }
        }

        return totalTriangles;
    }
};