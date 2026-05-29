#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers arr and an integer d. In one step you can jump from index i to index:
- i + x where: i + x < arr.length and 0 < x <= d.
- i - x where: i - x >= 0 and 0 < x <= d    
In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between min(i, j) and max(i, j). Return the maximum number of indices you can visit.

Approach: We can solve this problem using depth-first search (DFS) with memoization. The idea is to define a recursive function that computes the maximum number of jumps starting from a given index. We will use a memoization array to store the results of previously computed indices to avoid redundant calculations.

Steps:
1. Define a recursive function `dfs(i, arr, d, dp)` that takes the current index `i`, the array `arr`, the maximum jump distance `d`, and the memoization array `dp`.
2. If `dp[i]` is not -1, return the stored value, as it means we have already computed the maximum jumps from index `i`.
3. Initialize a variable `best` to 1, which represents the minimum number of jumps (the index itself).
4. Iterate through the possible jumps to the right (from `i + 1` to `i + d`) and check if the jump is valid (i.e., `arr[nxt] < arr[i]` and all elements between `i` and `nxt` are less than `arr[i]`). If valid, update `best` with the maximum of its current value and `1 + dfs(nxt, arr, d, dp)`.
5. Similarly, iterate through the possible jumps to the left (from `i - 1` to `i - d`) and check for validity. If valid, update `best` accordingly.
6. Store the computed value in `dp[i]` and return it.
7. In the main function `maxJumps(arr, d)`, initialize the memoization array `dp` with -1 and iterate through each index of the array, calling the `dfs` function to compute the maximum jumps from that index. Keep track of the overall maximum jumps and return it.

Time Complexity: O(n * d) in the worst case, where n is the length of the array and d is the maximum jump distance. This is because each index can potentially jump to d other indices.
Space Complexity: O(n) for the memoization array and the recursion stack in the worst case.
*/

class Solution {
public:
    int dfs(int i, vector<int>& arr, int d, vector<int>& dp) {
        if (dp[i] != -1)
            return dp[i];

        int best = 1;
        int n = arr.size();

        for (int nxt = i + 1; nxt <= min(n - 1, i + d); nxt++) {
            if (arr[nxt] >= arr[i])
                break;

            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }

        for (int nxt = i - 1; nxt >= max(0, i - d); nxt--) {
            if (arr[nxt] >= arr[i])
                break;

            best = max(best, 1 + dfs(nxt, arr, d, dp));
        }

        return dp[i] = best;
    }

    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        int ans = 1;

        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, arr, d, dp));
        }

        return ans;
    }
};z