#include <bits/stdc++.h>
using namespace std;

// Problem: Count Covered Buildings
// Approach: Boundary Tracking for Each Row and Column

// Steps:
// 1. Initialize four vectors to track the minimum and maximum x and y coordinates for each row and column.
// 2. Update these vectors based on the coordinates of each building.
// 3. Count buildings that are covered by checking if their coordinates lie strictly within the boundaries.
// 4. Return the count of covered buildings. 

// Time Complexity: O(n) where n is the number of buildings.
// Space Complexity: O(m) where m is the maximum coordinate value (for boundary tracking).

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int> minx(n + 1, n + 1);
        vector<int> maxx(n + 1, 0);
        vector<int> miny(n + 1, n + 1);
        vector<int> maxy(n + 1, 0);
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            minx[y] = min(minx[y], x);
            maxx[y] = max(maxx[y], x);
            miny[x] = min(miny[x], y);
            maxy[x] = max(maxy[x], y);
        }
        int ans = 0;
        for(auto b : buildings){
            int x = b[0];
            int y = b[1];
            if(minx[y] < x && x < maxx[y] && miny[x] < y && y < maxy[x]){
                ans += 1;
            }
        }
        return ans;
    }
};