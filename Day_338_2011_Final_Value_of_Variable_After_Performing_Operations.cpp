#include <bits/stdc++.h>
using namespace std;

// Problem: Calculate the final value of variable 'x' after performing a series of operations
// Approach: Simulation

// Steps:
// 1. Initialize the sizes of the version strings and variables to store numeric values of version segments (x1 and x2).
// 2. Use a loop to iterate through both version strings until all segments are processed.
// 3. Extract the numeric value of the current segment from v1 by iterating until a dot or the end of the string is encountered.
// 4. Similarly, extract the numeric value of the current segment from v2.
// 5. Compare the extracted numeric values (x1 and x2), returning -1 if x1 < x2, 1 if x1 > x2, and resetting both values to 0 if they are equal.
// 6. If all segments are equal, return 0 after the loop.

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;
        for(auto& op: operations)
            x+=(op[1]=='+')?1:-1;
        return x;
    }
};