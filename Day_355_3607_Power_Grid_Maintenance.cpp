#include <bits/stdc++.h>
using namespace std;

// Problem: Manage a power grid with n stations and connections, processing queries to take stations offline or find the smallest online station in the same component.
// Approach: Use Disjoint Set Union (DSU) to manage connected components and a min-heap for each component to efficiently retrieve the smallest online station.

// Steps:
// 1. Implement DSU class with path compression and union by rank.
// 2. Initialize DSU and online status for each station.
// 3. Union connected stations.
// 4. Create a min-heap for each connected component to track online stations.
// 5. Process queries to take stations offline or find the smallest online station in the same component.
// 6. Return results for type 1 queries.

// Time Complexity: O((n + q) * α(n)) where α is the inverse Ackermann function, n is number of stations, and q is number of queries.
// Space Complexity: O(n) for DSU and heaps.

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n + 1);
        for (int i = 0; i <= n; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        parent[py] = px;
        return true;
    }
};

class Solution {
public:
    vector<int> processQueries(int n, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(n);
        vector<bool> online(n + 1, true);

        for (auto& conn : connections) {
            int u = conn[0], v = conn[1];
            dsu.unite(u, v);
        }

        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> component_heap;
        for (int station = 1; station <= n; ++station) {
            int root = dsu.find(station);
            component_heap[root].push(station);
        }

        vector<int> result;

        for (auto& query : queries) {
            int type = query[0], x = query[1];
            if (type == 2) {
                online[x] = false;
            } else {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    int root = dsu.find(x);
                    auto& heap = component_heap[root];

                    while (!heap.empty() && !online[heap.top()]) {
                        heap.pop();
                    }

                    result.push_back(heap.empty() ? -1 : heap.top());
                }
            }
        }

        return result;
    }
};