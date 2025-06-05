#include<bits/stdc++.h>
using namespace std;
// This code defines a function to find the lexicographically smallest equivalent string
// based on two input strings that represent equivalence relations.

class Solution {
public:
    // Helper function: DFS to find the smallest lexicographical character
    // in the connected component containing 'cur'
    char dfs(unordered_map<char, vector<char>>& adj, char cur, vector<int>& vis) {
        vis[cur - 'a'] = 1; // Mark current character as visited
        char minChar = cur; // Initialize minimum character as current
        for (char neighbor : adj[cur]) {
            if (vis[neighbor - 'a'] == 0) {
                // Recursively visit neighbors and update minChar
                minChar = min(minChar, dfs(adj, neighbor, vis));
            }
        }
        return minChar;
    }

    // Main function to find the lexicographically smallest equivalent string
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        unordered_map<char, vector<char>> adj; // Adjacency list for equivalence graph

        // Step 1: Build the equivalence graph from s1 and s2
        for (int i = 0; i < n; ++i) {
            char u = s1[i];
            char v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Step 2: For each character in baseStr, find the smallest equivalent character
        string result;
        for (char ch : baseStr) {
            vector<int> vis(26, 0); // Visited array for DFS
            char minChar = dfs(adj, ch, vis); // Find smallest equivalent
            result.push_back(minChar);
        }

        return result;
    }
};