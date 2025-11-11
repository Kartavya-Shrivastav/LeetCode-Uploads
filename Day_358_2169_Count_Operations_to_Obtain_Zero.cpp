#include <bits/stdc++.h>
using namespace std;

// Problem: Given two non-negative integers num1 and num2, return the number of operations required to make either num1 or num2 equal to zero. In one operation, you can subtract the smaller number from the larger number.
// Approach: Use a recursive approach to repeatedly subtract the smaller number from the larger one, counting the number of operations until one of the numbers reaches zero.

// Steps:
// 1. Check if either num1 or num2 is zero; if so, return the count of operations.
// 2. Use division to determine how many times the smaller number can be subtracted from the larger number.
// 3. Recursively call the function with the updated values and increment the operation count accordingly.

// Time Complexity: O(log(min(num1, num2))) due to the nature of the Euclidean algorithm.
// Space Complexity: O(1) for the count variable.

class Solution {
public:
    int countOperations(int num1, int num2, int cnt=0) {
        if (num1==0 || num2==0) return cnt;
    //    if (num1<num2) return countOperations(num2, num1, cnt);
        auto [q, r]=div(num1, num2);
        return countOperations(num2, r, cnt+q);
    }
};