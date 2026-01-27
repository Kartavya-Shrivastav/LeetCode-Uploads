#include <bits/stdc++.h>
using namespace std;

// Problem: 3650. Minimum Cost Path with Edge Reversals
// Given a directed graph with weighted edges, find the minimum cost to reach from node 0 to node n-1,
// where reversing an edge incurs double the cost of traversing it in the original direction.

// Approach: Use Dijkstra's algorithm to find the shortest path in a modified graph where each edge can be traversed
// in both directions, with the cost of reversing an edge being double the original cost.

// Steps:
// 1. Construct an adjacency list for the graph, adding both the original edges and the reversed edges with double cost.
// 2. Initialize a priority queue to implement Dijkstra's algorithm.
// 3. Maintain a distance array to track the minimum cost to reach each node.
// 4. Process nodes from the priority queue, updating distances for adjacent nodes as shorter paths are found.
// 5. Return the minimum cost to reach node n-1, or -1 if it is unreachable.

// Time Complexity: O((V + E) log V) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E) for the adjacency list and distance array.

// with packing data into uint64
using u16=unsigned short;
using u64=unsigned long long;
using info=pair<unsigned, u16>; // (distance, vertex)

const int N=50000;
vector<u64> adj[N];
unsigned dist[N];

class Solution {
public:
    static inline u64 pack(int w, int v){ return ((u64)w<<16)|v; }
    static inline void build_adj(int n, vector<vector<int>>& edges) {
        for (int i=0; i<n; i++) adj[i].clear();

        for (const auto& e : edges) {
            int w=e[2], u=e[0], v=e[1];
            adj[u].push_back(pack(w, v));     // normal edge
            adj[v].push_back(pack(2*w, u));   // reversed edge
        }
    }

    static int minCost(int n, vector<vector<int>>& edges) {
        build_adj(n, edges);

        priority_queue<u64, vector<u64>, greater<>> pq;

        memset(dist, 255, sizeof(unsigned)*n);// fill with UINT_MAX

        dist[0]=0;
        pq.emplace(0);

        while (!pq.empty()) {
            u64 data=pq.top();
            int d=data>>16, u=data&USHRT_MAX;
            pq.pop();

            if (d>dist[u]) continue;
            if (u==n-1) return d;

            for (auto& wv : adj[u]) {
                int w=wv>>16, v=wv&USHRT_MAX;
                unsigned d2=d+w;

                if (d2<dist[v]) {
                    dist[v]=d2;
                    pq.push(pack(d2, v));
                }
            }
        }
        return -1;
    }
};
