#include <bits/stdc++.h>
using namespace std;

// Problem: Count Number of Trapezoids II
// Approach: Hashing Slopes and Intercepts

// Steps:
// 1. For each pair of points, calculate the slope (k) and y-intercept (b) of the line formed by the points.
// 2. Use a hash map to group lines by their slopes and store their intercepts.
// 3. Use another hash map to group lines by the midpoint of the points and store their slopes.
// 4. Count the number of trapezoids formed by lines with the same slope but different intercepts.
// 5. Subtract the count of trapezoids formed by lines with the same midpoint to avoid double counting.
// 6. Return the final count of trapezoids.

// Time Complexity: O(n^2) where n is the number of points (due to pairwise combinations)
// Space Complexity: O(n^2) for storing slopes and intercepts

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        int inf = 1e9 + 7;
        unordered_map<float, vector<float>> slopeToIntercept;
        unordered_map<int, vector<float>> midToSlope;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;
                float k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (float)(y2 - y1) / (x2 - x1);
                    b = (float)(y1 * dx - x1 * dy) / dx;
                }
                int mid = (x1 + x2) * 10000 + (y1 + y2);
                slopeToIntercept[k].push_back(b);
                midToSlope[mid].push_back(k);
            }
        }
        for (auto& [_, sti] : slopeToIntercept) {
            if (sti.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float b : sti) {
                cnt[b]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans += sum * count;
                sum += count;
            }
        }
        for (auto& [_, mts] : midToSlope) {
            if (mts.size() == 1) {
                continue;
            }
            map<float, int> cnt;
            for (float k : mts) {
                cnt[k]++;
            }
            int sum = 0;
            for (auto& [_, count] : cnt) {
                ans -= sum * count;
                sum += count;
            }
        }
        return ans;
    }
};