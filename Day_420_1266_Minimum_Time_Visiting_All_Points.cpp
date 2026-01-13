#include <bits/stdc++.h>
using namespace std;    

// Problem: 1266. Minimum Time Visiting All Points
// Approach: Greedy calculation of maximum of horizontal and vertical distances between consecutive points.

// Steps:
// 1. Initialize a variable to keep track of the total time.    
// 2. Iterate through the list of points starting from the second point.
//    - For each point, calculate the absolute difference in x-coordinates and y-coordinates with the previous point.
//    - The time to move from the previous point to the current point is the maximum of these two differences.
//    - Accumulate this time into the total time variable.  
// 3. Return the total time after processing all points.

// Time Complexity: O(n), where n is the number of points.
// Space Complexity: O(1), as we are using only a constant amount of extra space

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& p) {
        int ans = 0;
        for (int i = 1; i < p.size(); i++) {
            ans += max(
                abs(p[i][0] - p[i - 1][0]),
                abs(p[i][1] - p[i - 1][1])
            );
        }
        return ans;
    }
};