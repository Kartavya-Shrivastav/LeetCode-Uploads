#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers, transform the array such that each element at index i is replaced by the value of the element at index (i + A[i]) % n, where n is the length of the array. Return the transformed array.
// Approach: We can use a two-pass approach to achieve the transformation in-place. In the first pass, we can encode both the original and the new values in the same integer using bit manipulation. In the second pass, we can decode the new values to get the final transformed array.

// Steps:
// 1. Define an OFFSET to ensure that all values are positive and can be encoded without overlap.
// 2. In the first pass, for each element at index i, calculate the new index using (i + A[i]) % n and encode the new value at that index into the current element using bit manipulation.
// 3. In the second pass, decode the new values from the encoded integers to get the final transformed array.
// 4. Return the transformed array.

// Time Complexity: O(N), where N is the number of elements in the array, as we traverse the array twice.
// Space Complexity: O(1), as we are modifying the array in-place without using any additional data structures.

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& A) {
        int n = A.size();
        int OFFSET = 1 << 7;
        int MASK = (1 << 8) - 1;

        for (int i = 0; i < n; i++)
            A[i] += OFFSET;

        for (int i = 0; i < n; i++) {
            int cur = A[i] - OFFSET;
            int idx = ((i + cur) % n + n) % n;
            int val = A[idx] & MASK;
            A[i] |= val << 8;
        }

        for (int i = 0; i < n; i++)
            A[i] = (A[i] >> 8) - OFFSET;

        return A;
    }
};