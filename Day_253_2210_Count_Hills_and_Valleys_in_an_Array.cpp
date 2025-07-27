#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of hills and valleys in an integer array.
// A hill is where nums[i] > both neighbors, and a valley is where nums[i] < both neighbors.
// Adjacent duplicates are ignored to avoid false hills/valleys.

// Approach: Skip duplicates and compare current element with the previous non-duplicate (left) and next element.

// Steps:
// 1. Initialize `count` to 0 and `left` pointer to 0.
// 2. Loop from index 1 to n-2, checking only non-duplicate sequences.
// 3. If nums[i] is greater than both neighbors, increment count (hill).
// 4. If nums[i] is smaller than both neighbors, increment count (valley).
// 5. Update `left` to current index for next comparison.

// Time Complexity: O(n), where n is the length of the array.
// Space Complexity: O(1), constant extra space.

class Solution {
public:
    int countHillValley(std::vector<int>& nums) {
        int count = 0;
        int left = 0;

        for (int i = 1; i < nums.size() - 1; ++i) {
            if (nums[i] != nums[i + 1]) {
                if ((nums[i] > nums[left] && nums[i] > nums[i + 1]) ||
                    (nums[i] < nums[left] && nums[i] < nums[i + 1])) {
                    ++count;
                }
                left = i;
            }
        }

        return count;
    }
};