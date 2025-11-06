#include <bits/stdc++.h>
using namespace std;

// Problem: The Two Sneaky Numbers of Digitville
// Approach: Use XOR to find the two missing numbers in the array

// Steps:
// 1. Compute the XOR of all numbers in the array and all numbers from 0
// 2. Find a set bit in the XOR result to differentiate the two missing numbers
// 3. Partition the numbers into two groups based on the set bit and compute XOR for each group
// 4. The results of the two groups will be the two missing numbers

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int XOR = 0;
        int n = nums.size() - 2;

        for (int num : nums) XOR ^= num;            
        for (int i = 0; i < n; i++) XOR ^= i;
        //for (int i = 0; i < n; i++) XOR ^= nums[i] ^ (i < n ? i : 0); //single-pass

        int diffBit = XOR & -XOR;

        int a = 0, b = 0;
        for (int num : nums) {
            if ((num & diffBit) == 0) a ^= num;
            else b ^= num;
        }
        for (int i = 0; i < n; i++) {
            if ((i & diffBit) == 0) a ^= i;
            else b ^= i;
        }

        return {a, b};
    }
};