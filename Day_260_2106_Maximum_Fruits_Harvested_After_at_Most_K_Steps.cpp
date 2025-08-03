#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Fruits Harvested After at Most K Steps
// Approach: Use a sliding window technique to find the maximum number of fruits that can be harvested within the constraints of the 
//           number of steps allowed.

// Steps:
// 1. Initialize two pointers for the sliding window: left and right.
// 2. Maintain a sum of fruits in the current window and a variable to track the maximum number of fruits harvested.
// 3. Expand the right pointer to include more fruits and add their counts to the sum.
// 4. If the minimum steps required to harvest from the current window exceeds K, move
//    the left pointer to reduce the window size and subtract the leftmost fruit's count from the sum.
// 5. Update the maximum number of fruits harvested whenever a valid window is found.
// 6. Return the maximum number of fruits harvested.

// Time Complexity: O(n) where n is the number of fruit types, as each fruit type is processed at most twice 
//                  (once by the left pointer and once by the right pointer).
// Space Complexity: O(1) for the sliding window pointers and sum variable, O(n) for the input vector of fruits.

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0, sum = 0, maxFruits = 0;
        for (int right = 0; right < fruits.size(); ++right) {
            sum += fruits[right][1];
            while (left <= right && minSteps(fruits[left][0], fruits[right][0], startPos) > k) {
                sum -= fruits[left][1];
                left++;
            }
            maxFruits = max(maxFruits, sum);
        }
        return maxFruits;
    }

    int minSteps(int left, int right, int start) {
        return min(abs(start - left) + (right - left),
                   abs(start - right) + (right - left));
    }
};