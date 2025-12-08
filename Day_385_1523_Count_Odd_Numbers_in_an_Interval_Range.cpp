#include <iostream>
using namespace std;

// Problem: Count Odd Numbers in an Interval Range
// Approach: Mathematical Calculation

// Steps:
// 1. Calculate the number of odd numbers from 1 to high using (high + 1) / 2.
// 2. Calculate the number of odd numbers from 1 to low - 1 using (low) / 2.
// 3. Subtract the two results to get the count of odd numbers in the interval [low, high].

// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int countOdds(int low, int high) {
        return (high + 1) / 2 - (low / 2);
    }
};