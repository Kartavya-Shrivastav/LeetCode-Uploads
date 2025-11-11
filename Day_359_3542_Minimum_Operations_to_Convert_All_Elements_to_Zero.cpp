#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers, find the minimum number of operations required to convert all elements to zero. In one operation, you can choose a contiguous subarray and decrease each element by 1.
// Approach: Use a stack-based approach to track the heights of the elements and count the number of operations needed to reduce them to zero.

// Steps:
// 1. Initialize a stack to keep track of the heights of the elements.
// 2. Iterate through each element in the array.
// 3. For each element, pop from the stack until the top of the stack is less than or equal to the current element, counting the number
//    of pops as operations.
// 4. If the current element is not equal to the top of the stack, push it onto the stack.
// 5. Finally, return the total number of operations plus the size of the stack (which represents the remaining heights).

// Time Complexity: O(n) where n is the number of elements in the array.
// Space Complexity: O(n) for the stack.


class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> stack(nums.size() + 1, 0);
        int top = 0, ans = 0;
        for (int num : nums) {
            while (stack[top] > num) {
                top--;
                ans++;
            }
            if (stack[top] != num)
                stack[++top] = num;
        }
        return ans + top;
    }
};