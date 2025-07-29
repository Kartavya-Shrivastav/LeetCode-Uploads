#include <bits/stdc++.h>
using namespace std;

// Problem: Find the smallest subarrays for each element in an array such that the bitwise OR of the subarray is equal to the element.
// Approach: Use a greedy method to track the last seen index of each bit in the binary representation of the numbers.

// Steps:
// 1. Initialize an array to store the smallest subarray lengths.
// 2. Iterate through the array from the end to the beginning.
// 3. For each element, determine the last seen index of each bit in its binary representation.
// 4. Update the last seen index for each bit if it is set in the current number.
// 5. Calculate the length of the smallest subarray that includes the current element and all bits set in it.
// 6. Store the result in the answer array.
// 7. Return the answer array containing the lengths of the smallest subarrays for each element.

// Time Complexity: O(n * 30), where n is the number of elements in the array and 30 is the number of bits considered (for 32-bit integers).
// Space Complexity: O(30) for the last seen indices of bits.  


class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        const int n=nums.size();
        vector<int> ans(n);
        vector<int> last(30, -1); // last seen index of each bit

        for (int i=n-1; i>= 0; i--) {
            const unsigned x=nums[i];
            int j=i;
            bitset<30> X(x);
            for (int b=0; b<30; b++) {
                if (X[b]) 
                    last[b]=i;
                j=max(j, last[b]);
            }
            ans[i]=j-i+1;
        }

        return ans;
    }
};