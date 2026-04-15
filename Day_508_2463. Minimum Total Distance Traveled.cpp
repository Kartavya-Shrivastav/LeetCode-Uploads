#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given two arrays, robot and factory, where robot[i] is the position of the i-th robot and factory[j] = [position, limit] is the position and maximum number of robots that can be repaired at the j-th factory, return the minimum total distance between each robot and its assigned factory. The distance between a robot at position x and a factory at position y is |x - y|
Approach: Sort both arrays and use dynamic programming to find the minimum total distance. The state dp[i][j] represents the minimum total distance when assigning the first i robots to the first j factories. We can either skip the j-th factory or assign k robots to it (where k is less than or equal to the limit of the factory) and calculate the cost accordingly.

Steps:
1. Sort the robot and factory arrays based on their positions.
2. Initialize a dp array of size n x m with -1 to store the results of subproblems.
3. Define a recursive function solve(i, j) that returns the minimum total distance when assigning the first i robots to the first j factories.
4. In the solve function, if all robots are assigned (i == n), return 0. If no factories are left (j == m), return a large number (indicating an invalid assignment).
5. If the result for dp[i][j] is already computed, return it.

Time Complexity: O(n * m * limit) where n is the number of robots, m is the number of factories, and limit is the maximum number of robots that can be repaired at any factory.
Space Complexity: O(n * m) for the dp array.
*/

class Solution {
public:
    vector<vector<long long>> dp;

    long long solve(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        int n = robot.size();
        int m = factory.size();

        // all robots assigned
        if (i == n) return 0;

        // no factory left
        if (j == m) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long res = solve(i, j + 1, robot, factory); // skip factory

        long long cost = 0;
        int pos = factory[j][0];
        int limit = factory[j][1];

        // assign k robots
        for (int k = 0; k < limit && i + k < n; k++) {
            cost += abs(robot[i + k] - pos);
            res = min(res, cost + solve(i + k + 1, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        dp.assign(n, vector<long long>(m, -1));

        return solve(0, 0, robot, factory);
    }
};