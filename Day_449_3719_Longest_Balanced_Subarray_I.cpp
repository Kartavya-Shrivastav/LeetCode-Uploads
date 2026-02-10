#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary array nums, return the length of the longest balanced subarray. A balanced subarray is a subarray that contains an equal number of 0's and 1's.
// Approach: We can use a brute-force approach to check all possible subarrays and count the number of 0's and 1's in each subarray. We can maintain a count of 0's and 1's in an array A of size 2, where A[0] represents the count of 0's and A[1] represents the count of 1's. We can use a marker to keep track of which subarrays we have already seen to avoid counting the same subarray multiple times. If we find a balanced subarray (where A[0] == A[1]), we can update our result with the length of that subarray.

// Steps:
// 1. Initialize a variable res to store the length of the longest balanced subarray and a variable leet to keep track of the current marker.
// 2. Iterate through the input array nums using two nested loops to check all possible subarrays. The outer loop will iterate through the starting index i of the subarray, and the inner loop will iterate through the ending index j of the subarray.
// 3. For each subarray defined by the indices i and j, we will maintain a count of 0's and 1's in an array A of size 2. We will use a marker to keep track of which subarrays we have already seen to avoid counting the same subarray multiple times. If we encounter a value that we haven't seen before in the current subarray, we will update the count in A and mark it as seen using the marker.
// 4. If we find a balanced subarray (where A[0] == A[1]), we will update our result with the length of that subarray (j - i + 1).
// 5. After checking all possible subarrays, we will return the value of res as the length of the longest balanced subarray.

// Time Complexity: O(n^2), where n is the length of the input array. We check all possible subarrays, and for each subarray, we count the number of 0's and 1's in O(1) time.
// Space Complexity: O(1), as we are using a fixed-size array A to count the number of 0's and 1's, and a marker to keep track of seen subarrays.

class Solution {
public:
    inline static uint32_t seen[100001] = {};
    inline static uint32_t leet = 0;
    int longestBalanced(vector<int>& nums) {
        leet++;
        int n = nums.size();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int A[2] = {0, 0};
            uint32_t marker = (leet << 16) | (uint32_t)(i + 1);
            for (int j = i; j < n; j++) {
                int val = nums[j];
                if (seen[val] != marker) {
                    seen[val] = marker;
                    A[val & 1]++;
                }

                if (A[0] == A[1])
                    res = max(res, j - i + 1);
            }
        }

        return res;
    }
};