#include<bits/stdc++.h>
using namespace std;

// Problem: Rearrange the elements of an array based on their absolute difference from a given integer x.
// Approach is to use a multimap to store the absolute differences and their corresponding elements, then sort them based on the differences.
// Steps:
// 1. Create a multimap to store pairs of absolute difference and the corresponding element.
// 2. Iterate through the array and insert each element into the multimap with its absolute difference from x.
// 3. Iterate through the multimap and fill the original array with the sorted elements.

// Time Complexity: O(n log n) due to the multimap operations, where n is the number of elements in the array.
// Space Complexity: O(n) for storing the elements in the multimap.

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k - 1 + maxPts) return 1.0;

        vector<double> dp(maxPts, 0.0);
        dp[0] = 1.0;

        double windowSum = 1.0, result = 0.0;

        for (int i = 1; i <= n; i++) {
            double prob = windowSum / maxPts;

            if (i < k) {
                windowSum += prob;
            } else {
                result += prob;
            }

            if (i >= maxPts) {
                windowSum -= dp[i % maxPts];
            }

            dp[i % maxPts] = prob;
        }

        return result;
    }
};