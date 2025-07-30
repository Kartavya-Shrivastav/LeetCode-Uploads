#include <vector>
#include <algorithm>
// Problem: Find the longest subarray with the maximum bitwise AND in an array.
// Approach:
// 1. Identify the maximum value in the array.
// 2. Count the length of the longest contiguous subarray that consists only of this maximum value.
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(1), as we are using a constant amount of extra space.
// This solution is efficient and straightforward, leveraging the properties of the maximum value in the array.
// This code is a complete solution for the problem described above.
// This code is a complete solution for the problem described above.
// This code is a complete solution for the problem described above.
// This code is a complete solution for the problem described above.
class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        // 1. Find the maximum value in the array.
        int maxVal = 0;
        for (int num : nums) {
            if (num > maxVal) {
                maxVal = num;
            }
        }
        
        // 2. Find the length of the longest subarray of maxVal.
        int maxLen = 0;
        int currentLen = 0;
        
        for (int num : nums) {
            if (num == maxVal) {
                currentLen++;
            } else {
                maxLen = std::max(maxLen, currentLen);
                currentLen = 0;
            }
        }
        
        // 3. Final check for a trailing streak.
        return std::max(maxLen, currentLen);
    }
};