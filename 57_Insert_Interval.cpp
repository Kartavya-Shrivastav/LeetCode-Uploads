#include <bits/stdc++.h>
using namespace std;

// Class to insert a new interval into a list of non-overlapping intervals

class Solution {
public:
    // Inserts a new interval into a list of non-overlapping intervals and merges if necessary
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res; // Result vector to store merged intervals

        for (const auto& interval : intervals) {
            // If the new interval is before the current interval and does not overlap
            if (newInterval[1] < interval[0]) {
                res.push_back(newInterval); // Add the new interval
                newInterval = interval;     // Update newInterval to current interval
            }
            // If the new interval is after the current interval and does not overlap
            else if (newInterval[0] > interval[1]) {
                res.push_back(interval);    // Add the current interval
            }
            // Overlapping intervals, merge them
            else {
                newInterval[0] = min(newInterval[0], interval[0]);
                newInterval[1] = max(newInterval[1], interval[1]);
            }
        }

        // Add the last interval
        res.push_back(newInterval);
        return res;
    }
};