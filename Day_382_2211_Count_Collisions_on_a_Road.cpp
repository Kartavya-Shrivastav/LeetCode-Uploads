#include <bits/stdc++.h>
using namespace std;

// Problem: Count Collisions on a Road
// Approach: Two-Pointer Trimming and Counting

// Steps:
// 1. Use two pointers to trim off leading 'L' cars and trailing 'R' cars since they will never collide.
// 2. Count the remaining 'L' and 'R' cars in the trimmed string as they will eventually collide.
// 3. Return the count of these cars as the number of collisions.

// Time Complexity: O(n) where n is the length of the directions string
// Space Complexity: O(1) as we are using only a few extra variables

class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();

        // Remove leading 'L'
        int left = 0;
        while (left < n && directions[left] == 'L')
            left++;

        // Remove trailing 'R'
        int right = n - 1;
        while (right >= 0 && directions[right] == 'R')
            right--;

        // Count remaining 'L' and 'R'
        int collisions = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] == 'L' || directions[i] == 'R')
                collisions++;
        }

        return collisions;
    }
};
