#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a list of conflicting pairs, find the maximum number of subarrays after removing one conflicting pair.
// Approach: Use a greedy strategy to track the maximum subarrays while considering the conflicts.

// Steps:
// 1. Initialize two arrays to track the maximum and second maximum conflicting pairs.
// 2. Iterate through the conflicting pairs and update the maximum and second maximum values.
// 3. Calculate the total number of subarrays by iterating through the array and considering the conflicts.
// 4. Return the total count of subarrays after considering the conflicts.

// Time Complexity: O(N), where N is the number of conflicting pairs.
// Space Complexity: O(N), for storing the maximum and second maximum conflicting pairs.

class Solution {
public:
    long long maxSubarrays(const int n, vector<vector<int>>& cp) {
        vector<int> s(n + 1), s2(n + 1);
        for (auto& p : cp) {
            if (p[0] > p[1]) swap(p[0], p[1]);
            if (s[p[1]] < p[0]) {
                s2[p[1]] = s[p[1]];
                s[p[1]] = p[0];
            } else if (s2[p[1]] < p[0]) {
                s2[p[1]] = p[0];
            }
        }
        int m1 = 0, m2 = 0;
        int64_t ans = 0, delta = 0, md = 0;
        for (int i = 1; i <= n; ++i) {
            if (s[i] > 0) {
                if (s[i] > m1) {
                    m2 = max(m1, s2[i]);
                    m1 = s[i];
                    md = max(md, delta);
                    delta = 0;
                } else if (s[i] > m2) {
                    m2 = s[i];
                }
            }
            ans += i - m1;
            delta += m1 - m2;
        }
        return ans + max(md, delta);
    }
};