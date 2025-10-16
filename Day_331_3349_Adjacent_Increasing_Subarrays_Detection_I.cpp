#include <bits/stdc++.h>
using namespace std;

// Steps:
// 1. Initialize variables to track the length of the current increasing subarray (`inc`), the length of the previous increasing subarray
//    (`prevInc`), and the maximum length found so far (`maxLen`).  
// 2. Iterate through the array starting from the second element.
// 3. For each element, check if it is greater than the previous element.   
//    - If it is, increment the `inc` counter.  
//    - If it is not, update `prevInc` to the value of `inc and reset `inc` to 1.  
// 4. Calculate the potential maximum length of an increasing subarray that can be formed by either taking half of the current `inc` length
//    or the minimum of `prevInc` and `inc`.
// 5. Update the `maxLen` if the calculated candidate is greater than the current `maxLen`.  
// 6. If at any point `maxLen` is greater than or equal to `k`, return true.  
// 7. If the loop completes and `maxLen` is still less than `k`, return false.

// Time Complexity: O(n), where n is the length of the input array. We traverse the array once.
// Space Complexity: O(1), as we use a constant amount of extra space.

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), inc = 1, prevInc = 0, maxLen = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) inc++;
            else {
                prevInc = inc;
                inc = 1;
            }
            maxLen = max(maxLen, max(inc >> 1, min(prevInc, inc)));
            if (maxLen >= k) return true;
        }
        return false;
    }
};