#include <bits/stdc++.h>
using namespace std;

// Problem: Find Subsequence of Length K With the Largest Sum
// Approach: Sort the array, select the top k elements, and return them in their original order.

// Steps:
// 1. Create a vector of pairs to store each element and its index.
// 2. Sort this vector based on the values in descending order.
// 3. Select the top k elements from the sorted vector.
// 4. Sort these k elements based on their original indices to maintain the order.
// 5. Extract the values from the sorted k elements and return them.
// 6. Return the result vector containing the k largest elements in their original order.

// Time Complexity: O(n log n) for sorting, where n is the size of the input array.
// Space Complexity: O(n) for storing the pairs of values and indices.

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> numsWithIndices;
        for (int i = 0; i < nums.size(); i++) {
            numsWithIndices.push_back({nums[i], i});
        }

        // Sort by value descending
        sort(numsWithIndices.begin(), numsWithIndices.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        // Take top k and sort by original index
        vector<pair<int, int>> topK(numsWithIndices.begin(), numsWithIndices.begin() + k);
        sort(topK.begin(), topK.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        // Extract values
        vector<int> result;
        for (auto& p : topK) {
            result.push_back(p.first);
        }

        return result;
    }
};