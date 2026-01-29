#include <bits/stdc++.h>
using namespace std;

// Problem: 2976. Minimum Cost to Convert String I
// Given two strings source and target of equal length, and a list of character conversion operations with associated costs,
// find the minimum cost to convert source into target using the given operations. If it's not possible, return -1.

// Approach: Use the Floyd-Warshall algorithm to find the minimum cost of converting each character to every other character.
// Steps:
// 1. Initialize a 26x26 cost matrix for all lowercase letters, setting the cost of converting a character to itself as 0 and others as infinity.
// 2. Update the cost matrix with the given conversion operations.
// 3. Apply the Floyd-Warshall algorithm to compute the minimum conversion costs between all pairs of characters.
// 4. For each character in source, check the cost to convert it to the corresponding character in target and accumulate the total cost.
// 5. If any character cannot be converted, return -1; otherwise, return the total cost.

// Time Complexity: O(26^3 + n) where n is the length of the strings.
// Space Complexity: O(1) since the cost matrix size is constant (26x26).

class Solution {
public:
    long long minimumCost(string source, string target,
 vector<char>& original, vector<char>& changed, vector<int>& cost) {
        long long dist[26][26];
        const long long INF = 1e14;

        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                dist[i][j] = (i == j) ? 0 : INF;
            }
        }

        for (size_t i = 0; i < original.size(); ++i) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                if (dist[i][k] == INF) continue;
                for (int j = 0; j < 26; ++j) {
                    if (dist[k][j] != INF) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long long totalCost = 0;
        int n = source.length();

        for (int i = 0; i < n; ++i) {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (u == v) continue;
            if (dist[u][v] == INF) return -1;
            totalCost += dist[u][v];
        }

        return totalCost;
    }
};