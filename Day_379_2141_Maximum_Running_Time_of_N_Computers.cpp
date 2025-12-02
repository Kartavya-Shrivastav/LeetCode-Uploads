#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Running Time of N Computers
// Approach: Greedy with Sorting and Accumulation

// Steps:
// 1. Sort the battery capacities in ascending order.
// 2. Calculate the total sum of all battery capacities.
// 3. Iterate from the largest battery capacity to the smallest:    
//    - If the current battery capacity is less than or equal to the average capacity needed (total / n), break the loop.    
//    - Otherwise, subtract the current battery capacity from the total and decrease the number of computers (n) by one.
// 4. Finally, return the average capacity (total / n) as the maximum running time for all computers.

// Time Complexity: O(m log m) where m is the number of batteries (due to sorting)
// Space Complexity: O(1) if we ignore the input storage

class Solution {
public:
    long long maxRunTime(int n, vector<int>& arr) {
        sort(arr.begin(), arr.end());
        long long total = accumulate(arr.begin(), arr.end(), 0LL);

        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] <= total / n) break;
            total -= arr[i];
            n--;
        }

        return total / n;
    }
};
