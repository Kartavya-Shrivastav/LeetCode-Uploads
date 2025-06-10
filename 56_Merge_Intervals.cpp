#include <bits/stdc++.h>
using namespace std;

// Class to merge overlapping intervals
class Solution {
public:
    // Function to merge overlapping intervals
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // Sort intervals based on the start time
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        vector<vector<int>> merged; // Result vector to store merged intervals
        vector<int> prev = intervals[0]; // Initialize with the first interval

        // Iterate through the intervals
        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            // If current interval overlaps with the previous, merge them
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                // No overlap, add the previous interval to result
                merged.push_back(prev);
                prev = interval;
            }
        }

        // Add the last interval
        merged.push_back(prev);
        return merged;        
    }
};