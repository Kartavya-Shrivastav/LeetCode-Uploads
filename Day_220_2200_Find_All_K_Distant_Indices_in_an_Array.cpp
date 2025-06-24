#include <bits/stdc++.h>
using namespace std;

// Problem: Find All K-Distant Indices in an Array
// Approach: Identify indices in the array that are within k distance from any index containing the key

// Steps:
// 1. Iterate through the array to find all indices where the value equals the key.
// 2. For each index in the array, check if it is within k distance from any of the indices found in step 1.
// 3. If it is, add it to the result list.
// 4. Return the list of indices that are k-distant from the key indices.
// 5. Use absolute difference to check the distance condition.
// 6. Ensure to avoid duplicates in the result list.

// Time Complexity: O(n * m), where n is the size of the array and m is the number of indices with the key.
// Space Complexity: O(n) for storing the indices of the key.

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> idx; // Stores indices where nums[i] == key
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == key) idx.push_back(i); // Collect all indices of key
        }

        vector<int> res; // Result vector to store k-distant indices

        // For each index in nums, check if it is within k distance from any key index
        for(int i = 0; i < nums.size(); i++) {
            for(int j = 0; j < idx.size(); j++) {
                // If the absolute difference is within k, add to result and break
                if(abs(i - idx[j]) <= k) {
                    res.push_back(i);
                    break; // No need to check further key indices for this i
                }
            }
        }

        return res; // Return all k-distant indices
    }
};