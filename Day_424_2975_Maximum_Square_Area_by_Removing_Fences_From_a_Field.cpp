#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

// Problem Statement: Given a field of size m x n with some horizontal and vertical fences placed on it, we need to find the maximum area of a square that can be formed by removing some fences. The square must fit entirely within the field without being obstructed by any remaining fences.
// Approach: We can add the boundaries of the field to the list of fence positions. Then, we can calculate all possible distances between pairs of horizontal fences and store them in a set. Next, we calculate all possible distances between pairs of vertical fences and check if any of these distances exist in the set of horizontal distances. The largest common distance will determine the side length of the largest square that can be formed. Finally, we calculate the area of the square by squaring this side length.

// Steps:
// 1. Add the boundaries of the field to the list of horizontal and vertical fences.
// 2. Calculate all possible distances between pairs of horizontal fences and store them in a set.
// 3. Calculate all possible distances between pairs of vertical fences.
// 4. Check for common distances in both sets and find the maximum common distance.
// 5. Calculate the area of the square by squaring the maximum common distance.

// Time Complexity: O(h^2 + v^2), where h and v are the number of horizontal and vertical fences respectively, due to the nested loops for distance calculations.
// Space Complexity: O(h^2), for storing the distances between horizontal fences in a set.

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        unordered_set<int> stt;
        long long ans = 0;

        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                stt.insert(abs(hFences[j] - hFences[i]));
            }
        }

        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int val = abs(vFences[j] - vFences[i]);
                if (stt.count(val)) {
                    ans = max(ans, (long long)val);
                }
            }
        }

        if (ans == 0) {
            return -1;
        }

        long long MOD = 1e9 + 7;
        return (ans * ans) % MOD;
    }
};