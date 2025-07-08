#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of events where each event is represented by a start and end day, find the maximum value that can be obtained by attending at most k events.
// Approach: Use dynamic programming with binary search to find the maximum value of attended events.

// Steps:
// 1. Sort the events by their end day.
// 2. Use a DP table where dp[i][j] represents the maximum value obtainable by attending j events from the first i events.
// 3. For each event, use binary search to find the last event that ends before the current event starts.
// 4. Update the DP table by considering whether to attend the current event or not.
// 5. Return the maximum value obtainable by attending at most k events.

// Time Complexity - O(n log n) for sorting the events and O(n * k) for filling the DP table, where n is the number of events 
//                  and k is the maximum number of events that can be attended.
// Space Complexity - O(n * k) for the DP table.

class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int n = events.size();
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; ++i) {
            int prev = binarySearch(events, events[i - 1][0]);

            for (int j = 1; j <= k; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[prev + 1][j - 1] + events[i - 1][2]);
            }
        }

        return dp[n][k];
    }

private:
    int binarySearch(vector<vector<int>>& events, int currentStart) {
        int left = 0, right = events.size() - 1;
        int result = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (events[mid][1] < currentStart) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};