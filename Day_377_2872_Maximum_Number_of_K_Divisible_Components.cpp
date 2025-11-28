#include <bits/stdc++.h>
using namespace std;

// Problem: Maximum Number of K-Divisible Components in a Tree
// Approach: Depth-First Search (DFS) with Post-Order Traversal

// Steps:
// 1. Construct the tree using an adjacency list from the given edges.
// 2. Perform a DFS to determine the parent-child relationships and store nodes in a stack for post-order processing.
// 3. Initialize a sum array to keep track of the sum of values in each subtree.
// 4. Process nodes in post-order using the stack, checking if the subtree sum is divisible by k.
// 5. If divisible, increment the count of k-divisible components; otherwise, propagate the sum to the parent node.
// 6. Return the total count of k-divisible components.

// Time Complexity: O(n) where n is the number of nodes in the tree
// Space Complexity: O(n) for the adjacency list and other auxiliary data structures


class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int> > G(n);
        for(auto edge : edges){
            G[edge[0]].push_back(edge[1]);
            G[edge[1]].push_back(edge[0]);
        }
        stack <int> S;
        vector<int> parent(n);
        
        auto DFS = [&](int u, int p, auto &&DFS) -> void{
            parent[u] = p;
            S.push(u);
            for(auto v : G[u]){
                if(v == p) continue;
                DFS(v, u, DFS);
            }
        };
        DFS(0, -1, DFS);
        vector<long long> sum(n);
        for(int i = 0; i < n; i ++){
            sum[i] = values[i];
        }
        int ans = 0;
        while(!S.empty()){
            int u = S.top();
            S.pop();
            if(sum[u] % k == 0){
                ans += 1;
            }
            else{
                sum[parent[u]] += sum[u];
            }
        }
        return ans;
    }
};