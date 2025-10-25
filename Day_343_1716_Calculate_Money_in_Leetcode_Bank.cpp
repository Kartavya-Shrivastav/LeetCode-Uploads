#include <bits/stdc++.h>
using namespace std;

// Problem: Calculate Money in Leetcode Bank
// Approach: Use arithmetic series formulas to compute total money saved over n days.

// Steps:
// 1. Determine the number of complete weeks (q) and remaining days (r) using div function.
// 2. Calculate the total money saved in complete weeks using the formula for the sum of an arithmetic series.
// 3. Calculate the total money saved in the remaining days using the adjusted formula. 
// 4. Return the total money saved by summing the amounts from complete weeks and remaining days.

// Time Complexity: O(1) as calculations are done in constant time
// Space Complexity: O(1) as no additional space is used

class Solution {
public:
    int totalMoney(int n) {
        auto [q, r]=div(n, 7);
        return 28*q+7*q*(q-1)/2+(2*q+r+1)*r/2;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();