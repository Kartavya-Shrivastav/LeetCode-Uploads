#include <bits/stdc++.h>
using namespace std;

// Problem: Make Array Elements Equal to Zero
// Approach: Iterate through the array, maintaining prefix and suffix sums to count valid selections of zero elements.

// Steps:
// 1. Calculate the total sum of the array.
// 2. Iterate through each element, updating prefix and suffix sums.
// 3. For each zero element, check the conditions based on the difference between prefix and suffix sums.
// 4. Count the valid selections and return the result.

// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of extra space.


class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int leftSum = 0;
        int rightSum = sum;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1) {
                    ans++;
                }
                if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1) {
                    ans++;
                }
            } else {
                leftSum += nums[i];
                rightSum -= nums[i];
            }
        }
        return ans;
    }
};