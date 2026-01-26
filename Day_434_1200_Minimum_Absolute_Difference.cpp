#include <bits/stdc++.h>
using namespace std;

// Problem: 1200. Minimum Absolute Difference
// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.
// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] followsa, b are from arr and a < b, b - a equals to the minimum absolute difference

// Approach: Sort the array and then find the minimum absolute difference between consecutive elements. Collect all pairs that have this minimum difference.

// Steps:
// 1. Sort the input array arr.
// 2. Initialize a variable minDiff to store the minimum absolute difference, set it to a large value (INT_MAX).
// 3. Initialize a vector of vectors res to store the result pairs.
// 4. Iterate through the sorted array starting from the second element.
// 5. For each element, calculate the difference with the previous element.
// 6. If the calculated difference is less than minDiff, update minDiff and clear the result vector res, then add the current pair to res.
// 7. If the calculated difference is equal to minDiff, add the current pair to res.

// Time Complexity: O(n log n) due to sorting the array.
// Space Complexity: O(1) if we ignore the space used for sorting.

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& A) {
        sort(A.begin(), A.end());
        int minDiff = INT_MAX;
        vector<vector<int>> res;

        for (int i = 1; i < A.size(); i++) {
            int diff = A[i] - A[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                res = {};
                res.push_back({A[i - 1], A[i]});
            } else if (diff == minDiff)
                res.push_back({A[i - 1], A[i]});
        }

        return res;
    }
};