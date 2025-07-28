#include <bits/stdc++.h>
using namespace std;

// Problem: Count the number of subsets of an integer array that yield the maximum bitwise OR.
// Approach: Use backtracking to explore all subsets and count those that match the maximum OR.

// Steps:
// 1. Calculate the maximum bitwise OR of all elements in the array.
// 2. Use a recursive function to explore all subsets.
// 3. For each subset, check if its OR matches the maximum OR.
// 4. Count the number of valid subsets that yield the maximum OR.
// 5. Use bitwise operations to efficiently compute the OR of subsets.
// 6. Return the count of subsets that yield the maximum OR.

// Time Complexity: O(2^n), where n is the number of elements in the array.
// Space Complexity: O(n) for the recursion stack.

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for (int num : nums) {
            maxOR |= num;
        }
        return backtrack(nums, maxOR, 0, 0);
    }

private:
    int backtrack(vector<int>& nums, int maxOR, int index, int currentOR) {
        if (index == nums.size()) {
            return currentOR == maxOR ? 1 : 0;
        }

        if (currentOR == maxOR) {
            return 1 << (nums.size() - index);
        }

        return backtrack(nums, maxOR, index + 1, currentOR | nums[index]) +
               backtrack(nums, maxOR, index + 1, currentOR);
    }
};