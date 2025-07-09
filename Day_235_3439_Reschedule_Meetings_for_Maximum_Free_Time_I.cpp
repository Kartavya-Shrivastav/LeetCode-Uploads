#include <bits/stdc++.h>
using namespace std;

// Problem: Given a list of meetings with their start and end times, find the maximum free time available after scheduling k meetings.
// Approach: Use a prefix sum array to calculate the total time occupied by the meetings and then find the maximum free time available.

// Steps:
// 1. Create a prefix sum array to store the total time occupied by meetings up to each index.
// 2. Iterate through the meetings, updating the prefix sum array.
// 3. For each possible ending index of the k-th meeting, calculate the free time available before and after the meetings.
// 4. Keep track of the maximum free time found during the iterations.

// Time Complexity - O(n) for calculating the prefix sum and O(n) for finding the maximum free time, where n is the number of meetings.
// Space Complexity - O(n) for the prefix sum array.

class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        int res = 0;
        vector<int> sum(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + (endTime[i] - startTime[i]);
        }

        for (int i = k - 1; i < n; ++i) {
            int right = (i == n - 1) ? eventTime : startTime[i + 1];
            int left = (i == k - 1) ? 0 : endTime[i - k];
            int freeTime = right - left - (sum[i + 1] - sum[i - k + 1]);
            res = max(res, freeTime);
        }

        return res;
    }
};