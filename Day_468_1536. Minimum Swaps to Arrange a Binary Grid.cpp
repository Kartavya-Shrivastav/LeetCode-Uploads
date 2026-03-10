#include <bits/stdc++.h>
using namespace std;    

/*
Problem: Given an n x n binary grid, return the minimum number of swaps needed to arrange the grid such that all the cells above the main diagonal are 0. A swap consists of swapping any two rows of the grid.
Approach: We can count the number of trailing zeros in each row of the grid. Then, we need to ensure that for the i-th row (0-indexed), there are at least n - i - 1 trailing zeros. We can achieve this by swapping rows as needed.

Steps:
1. Create a vector zeros of size n to store the count of trailing zeros for each row.
2. Iterate through each row of the grid and count the number of trailing zeros, storing the count in the zeros vector.
3. Initialize a variable swaps to count the number of swaps needed. 
4. For each row i from 0 to n-1, calculate the number of trailing zeros needed (needed = n - i - 1).
5. If the current row does not have enough trailing zeros, look for a row below it that has enough trailing zeros and swap it up to the current position. Increment the swaps count for each swap made.
6. If we cannot find a suitable row to swap, return -1 as it is not possible to arrange the grid as required.   

Time Complexity: O(n^2), where n is the size of the grid. We need to count trailing zeros for each row and potentially swap rows, which can take O(n) time in the worst case.
Space Complexity: O(n) for the zeros vector to store the count of trailing zeros for each row.
*/

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> zeros(n);

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; j--) count++;
            zeros[i] = count;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            int needed = n - i - 1;
            int j = i;
            while (j < n && zeros[j] < needed) j++;
            if (j == n) return -1;
            while (j > i) {
                swap(zeros[j], zeros[j - 1]);
                j--;
                swaps++;
            }
        }

        return swaps;
    }
};