#include <bits/stdc++.h>
using namespace std;

// Problem: Find the maximum frequency of an element after performing operations
// Approach: Prefix Sum + Counting

// Steps:
// 1. Determine the maximum value in the input array and create a counting array to store frequencies.
// 2. Populate the counting array with the frequencies of each element in the input array.
// 3. Compute the prefix sum of the counting array to facilitate range frequency queries.
// 4. For each possible value in the counting array, calculate the total number of elements within the range [value - k, value + k].
// 5. Calculate the frequency of the current value and determine the maximum frequency achievable by adding
//    the minimum of numOperations and the difference between total elements in range and current frequency.
// 6. Return the maximum frequency found.

// Time Complexity: O(n + m) where n is the size of nums and m is the range of values
// Space Complexity: O(m)


class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxVal = *max_element(nums.begin(), nums.end()) + k + 2;
        int* count = new int[maxVal]();

        for (int v : nums)
            count[v]++;

        for (int i = 1; i < maxVal; i++)
            count[i] += count[i - 1];

        int res = 0;
        for (int i = 0; i < maxVal; i++) {
            int left = max(0, i - k);
            int right = min(maxVal - 1, i + k);
            int total = count[right] - (left ? count[left - 1] : 0);
            int freq = count[i] - (i ? count[i - 1] : 0);
            res = max(res, freq + min(numOperations, total - freq));
        }

        return res;
    }
};
