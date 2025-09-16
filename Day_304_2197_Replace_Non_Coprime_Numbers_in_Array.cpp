#include <bits/stdc++.h>
using namespace std;

// Problem: Replace non-coprime numbers in an array with their LCM until all numbers are coprime.
// Approach: Use a stack to keep track of the numbers and merge them when they are not coprime.

// Steps:
// 1. Iterate through each number in the array.
// 2. Use a stack to keep track of the numbers.
// 3. If the top of the stack and the current number are not coprime, merge them using LCM.
// 4. Continue until all numbers are coprime.

// Time Complexity: O(n * log(max(nums))) where n is the number of elements in nums.
// Space Complexity: O(n) for the stack.

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> stack;
        for (int num : nums) {
            while (!stack.empty()) {
                int top = stack.back();
                int g = gcd(top, num);
                if (g == 1) {
                    break;
                }
                stack.pop_back();
                // compute LCM
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            stack.push_back(num);
        }
        return stack;
    }
    
private:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};