#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a 2D grid of integers and an integer x, return the minimum number of operations required to make all the values in the grid the same. An operation consists of adding or subtracting x from any element in the grid. If it is not possible to make all the values in the grid the same, return -1.
Approach: We can first flatten the 2D grid into a 1D array for easier processing. We need to check if it is possible to make all values the same by verifying that the difference between any two elements in the array is divisible by x. If not, we can return -1 immediately. If it is possible, we can find the median of the array, as the optimal value to minimize the number of operations will be around the median. We can then calculate the total number of operations required to make all elements equal to this median value.

Steps:
1. Flatten the 2D grid into a 1D array.
2. Check if the difference between any two elements in the array is divisible by x. If not, return -1.
3. Use the nth_element function to find the median of the array.
4. Calculate the total number of operations required to make all elements equal to the median value by summing the absolute differences between each element and the median, divided by x.
5. Return the total number of operations as the answer.

Time Complexity: O(m*n) for flattening the grid and checking divisibility, O(n) for finding the median using nth_element, and O(n) for calculating the total operations, where m and n are the dimensions of the grid. Overall, the time complexity is O(m*n).
Space Complexity: O(m*n) for storing the flattened array, where m and n are the dimensions of the grid.
*/

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for (const vector<int>& row : grid)
        arr.insert(arr.end(), row.begin(), row.end());
        if (ranges::any_of(arr, [&](int a) { return (a - arr[0]) % x; }))
        return -1;

        int ans = 0;

        nth_element(arr.begin(), arr.begin() + arr.size() / 2, arr.end());

        for (const int a : arr)
        ans += abs(a - arr[arr.size() / 2]) / x;

        return ans; 
    }
};