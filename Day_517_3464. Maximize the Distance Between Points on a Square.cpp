#include <bits/stdc++.h>
using namespace std;

/*
Problem: You are given an integer side and a 2D integer array points where points[i] = [x, y] represents the coordinates of the ith point on a square with corners at (0, 0), (side, 0), (side, side), and (0, side). You are also given an integer k. Return the maximum distance between any two points in points such that there are at least k points in points that are at least that distance apart from each other.
Approach: We can use binary search to find the maximum distance. We will first convert the 2D coordinates of the points into a 1D representation based on their position on the square's perimeter. Then, we will sort these distances and use a helper function to check if there are at least k points that are at least a certain distance apart.

Steps:
1. Create a vector res to store the 1D representation of the points based on their position on the square's perimeter. For each point, calculate its distance from the starting point (0, 0) along the perimeter and store it in res.
2. Sort the res vector to have the distances in ascending order.
3. Define a helper function check that takes an integer n as input and checks if there are at least k points in res that are at least n distance apart. This function will use a two-pointer approach to count the number of points that satisfy the distance condition.
4. Use binary search to find the maximum distance. Initialize left to 1 and right to (side * 4) / k + 1. While left + 1 < right, calculate mid as the average of left and right. If check(mid) returns true, set left to mid; otherwise, set right to mid.
5. Return left as the maximum distance that satisfies the condition.

Time Complexity: O(n log n + n log m), where n is the number of points and m is the maximum distance we are checking in the binary search. Sorting the res vector takes O(n log n) time, and each check in the binary search takes O(n) time, with log m iterations in the worst case.
Space Complexity: O(n), where n is the number of points, since we are storing the 1D representation of the points in the res vector.
*/

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> res;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0) res.push_back(y);
            else if (y == side) 
                res.push_back((long long)side + x);
            else if (x == side) 
                res.push_back((long long)side * 3 - y);
            else res.push_back((long long)side * 4 - x);
        }
        sort(res.begin(), res.end());

        auto check = [&](int n) {
            int m = res.size();
            vector<int> idx(k);
            long long curr = res[0];
            idx[0] = 0;
            for (int i = 1; i < k; i++) {
                auto it = lower_bound(res.begin(), res.end(), curr + n);
                if (it == res.end()) 
                    return false;
                idx[i] = distance(res.begin(), it);
                curr = *it;
            }
            if (res[idx[k - 1]] - res[0] <= (long long)side * 4 - n) 
                return true;

            for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
                for (int j = 1; j < k; j++) {
                    while (idx[j] < m && res[idx[j]] < res[idx[j - 1]] + n) {
                        idx[j]++;
                    }
                    if (idx[j] == m) 
                        return false;
                }
                if (res[idx[k - 1]] - res[idx[0]] <= (long long)side * 4 - n) 
                    return true;
            }
            return false;
        };

        int left = 1;
        int right = (1LL * side * 4) / k + 1;
        while (left + 1 < right) {
            int mid = left + (right - left) / 2;
            if (check(mid)) 
                left = mid;
            else right = mid;
        }
        return left;
    }
};