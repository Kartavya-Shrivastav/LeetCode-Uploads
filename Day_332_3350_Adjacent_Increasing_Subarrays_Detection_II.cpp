#include <bits/stdc++.h>
using namespace std;

// Steps:
// 1. Initialize variables to track the length of the current increasing subarray (`up`), the length of the previous increasing subarray
//    (`preUp`), and the result (`res`).
// 2. Iterate through the array starting from the second element.
// 3. For each element, check if it is greater than the previous element.
//    - If it is, increment the `up` counter.
//    - If it is not, update `preUp` to the value of `up`, and reset `up` to 1.
// 4. Calculate the potential maximum length of an increasing subarray that can be formed by either taking half of the current `up` length
//    or the minimum of `preUp` and `up`.
// 5. Update the result `res` if the calculated candidate is greater than the current `res`.
// 6. Return the result `res` after iterating through the array.

// Time Complexity: O(n), where n is the length of the input array. We traverse the array once.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int up = 1, preUp = 0, res = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) up++;
            else {
                preUp = up;
                up = 1;
            }
            int half = up >> 1;
            int m = min(preUp, up);
            int candidate = max(half, m);
            if (candidate > res) res = candidate;
        }
        return res;
    }
};