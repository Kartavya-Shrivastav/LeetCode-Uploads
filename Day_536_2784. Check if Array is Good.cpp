#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given a 0-indexed integer array nums of length n. The array nums is good if it satisfies the following conditions:
1. nums.length == n - 1
2. nums[i] is in the range [0, n - 1] for every index i in the range [0, n - 2].
3. All the numbers in nums are distinct.
Approach: We can solve this problem by using a bitset to keep track of the numbers we have seen in the array. We will iterate through the array and check if each number is within the valid range (0 to n-1). If we encounter a number that is out of range, we can immediately return false. If we encounter a duplicate number, we need to check if it is the last number (n) and if we have already seen a duplicate before. If it is not the last number or if we have already seen a duplicate, we can return false. If we successfully iterate through the entire array without finding any issues, we can return true.

Steps:
1. Initialize a bitset seen of size 201 to keep track of the numbers we have seen in the array.
2. Initialize a boolean variable dup to keep track of whether we have seen a duplicate number.  
3. Iterate through each number in the nums array:
   a. If the number is greater than n (the last valid index), return false.
   b. If the number has already been seen (checked using the bitset), check if it is the last number (n) and if we have already seen a duplicate before. If it is not the last number or if we have already seen a duplicate, return false. Otherwise, set dup to true to indicate that we have now seen a duplicate.
   c. If the number has not been seen before, set it in the bitset to mark it as seen.
4. If we successfully iterate through the entire array without finding any issues, return true.

Time Complexity: O(n), where n is the length of the nums array. We iterate through the array once to check for validity and duplicates.
Space Complexity: O(1), since we are using a fixed-size bitset to keep track of the numbers we have seen, which does not depend on the size of the input array.
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        bitset<201> seen;
        bool dup = 0;

        for (auto& num : nums) {
            if (num > n) return false;

            if (seen.test(num)) {
                if (num < n || dup) return false;
                dup |= 1;
                continue;
            }

            seen.set(num);
        }

        return true;
    }
};