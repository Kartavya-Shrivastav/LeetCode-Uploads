#include <bits/stdc++.h>
using namespace std;

// Problem: Maximize the minimum power of all cities after adding additional power stations within a given range.
// Approach: Use binary search to find the maximum minimum power achievable. For each mid value, check if it's possible to achieve that power using a greedy approach with a sliding window.

// Steps:
// 1. Define a function to check if a given minimum power can be achieved.
// 2. Use binary search over the possible power values.
// 3. In the check function, use a sliding window to simulate adding power stations and verify if the minimum power can be met.
// 4. Return the maximum minimum power found.

// Time Complexity: O(n log(m)) where n is the number of cities and m is the range of possible power values.
// Space Complexity: O(n) for the temporary arrays used in the check function.

class Solution {
 public:
  long long maxPower(vector<int>& stations, int r, int k) {
    long left = ranges::min(stations);
    long right = accumulate(stations.begin(), stations.end(), 0L) + k + 1;
    while (left < right) {
      const long mid = (left + right) / 2;
      if (check(stations, r, k, mid))
        left = mid + 1;
      else
        right = mid;
    }
    return left - 1;
  }

 private:
  bool check(vector<int> stations, int r, int additionalStations,
             long minPower) {
    const int n = stations.size();
    long power = accumulate(stations.begin(), stations.begin() + r, 0L);

    for (int i = 0; i < n; ++i) {
      if (i + r < n)
        power += stations[i + r];
      if (power < minPower) {
        const long requiredPower = minPower - power;
        if (requiredPower > additionalStations)
          return false;
        stations[min(n - 1, i + r)] += requiredPower;
        additionalStations -= requiredPower;
        power += requiredPower;
      }
      if (i - r >= 0)
        power -= stations[i - r];
    }
    return true;
  }
};