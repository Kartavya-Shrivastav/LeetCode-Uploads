#include <bits/stdc++.h>
using namespace std;

// Problem: 1975. Maximum Matrix Sum
// Approach: We iterate through each element of the matrix to calculate the total sum of absolute values. We also count the number of negative elements and track the smallest absolute value in the matrix. If the count of negative elements is even, we can take all absolute values as is. If it's odd, we need to subtract twice the smallest absolute value from the total sum to maximize it.

// Steps:
// 1. Initialize variables to store the total sum of absolute values, count of negative numbers, and the minimum absolute value.
// 2. Loop through each element in the matrix:
//    - Add the absolute value of the element to the total sum.
//    - If the element is negative, increment the negative count.   
//    - Update the minimum absolute value if the current absolute value is smaller.
// 3. After processing all elements, check the parity of the negative count:
//    - If even, return the total sum.
//    - If odd, return the total sum minus twice the smallest absolute value.
// 4. Return the result.

// Time Complexity: O(m * n), where m and n are the dimensions of the matrix, as we need to visit each element once.    
// Space Complexity: O(1), as we are using a constant amount of extra space.

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int neg = 0;
        int minAbs = INT_MAX;

        for (auto& row : matrix) {
            for (int v : row) {
                if (v < 0) neg++;
                int av = abs(v);
                totalSum += av;
                minAbs = min(minAbs, av);
            }
        }

        return (neg % 2 == 0) ? totalSum : totalSum - 2LL * minAbs;
    }
};