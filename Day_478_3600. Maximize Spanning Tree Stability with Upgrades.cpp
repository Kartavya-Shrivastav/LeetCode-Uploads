#include <bits/stdc++.h>
using namespace std;

/*
Problems: Given a graph with n nodes and edges, where each edge has a weight and a type (0 for normal, 1 for must-have), and an integer k representing the number of upgrades allowed, find the maximum stability of a spanning tree that can be achieved by upgrading at most k normal edges to must-have edges. The stability of a spanning tree is defined as the minimum weight of the edges in the tree.
Approach:   
1. We can use a binary search approach to find the maximum stability. We will define a function check(X) that checks if it is possible to achieve a spanning tree with stability at least X by upgrading at most k normal edges.
2. In the check function, we will first create a DSU (Disjoint Set Union) to keep track of the connected components of the graph. We will first unite all the must-have edges that have weight at least X. If any must-have edge has weight less than X, we can immediately return false since it cannot be included in the spanning tree.
3. Next, we will unite all the normal edges that have weight at least X. This will help us to connect the components formed by the must-have edges.
4. After processing the must-have and normal edges, we will check how many components are left  and how many upgrades we have used. If the number of components minus one is greater than k, it means we cannot connect all components with the allowed upgrades, so we return false.
5. Finally, we will check if we can connect the remaining components using the normal edges that have weight less than X but at least X/2. If we can connect all components, we return true.
6. We will perform a binary search on the range of possible stability values to find the maximum stability that can be achieved.    

Time Complexity: O(E log W) where E is the number of edges and W is the range of edge weights due to the binary search and DSU operations.
Space Complexity: O(n) for the DSU data structure.
*/

class Solution {
    class DSU {
        vector<int> parent;
        vector<int> size;
    public:
        DSU(int n) {
            parent.resize(n);
            size.assign(n, 1);
            iota(parent.begin(), parent.end(), 0);
        }
        
        int find(int i) {
            if (parent[i] == i)
                return i;
            return parent[i] = find(parent[i]);
        }
        
        bool unite(int i, int j) {
            int root_i = find(i);
            int root_j = find(j);
            if (root_i != root_j) {
                if (size[root_i] < size[root_j])
                    swap(root_i, root_j);
                parent[root_j] = root_i;
                size[root_i] += size[root_j];
                return true;
            }
            return false;
        }
    };

    bool check(long long X, int n, const vector<vector<int>>& edges, int k) {
        DSU dsu(n);
        int comps = n;
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (e[2] < X) return false;
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        if (comps - 1 > k) return false;
        
        for (const auto& e : edges) {
            if (e[3] == 0 && e[2] < X && 2LL * e[2] >= X) {
                if (dsu.unite(e[0], e[1])) comps--;
            }
        }
        
        return comps == 1;
    }

public:
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU init_dsu(n);
        long long max_must_s = 2e9; 
        
        for (const auto& e : edges) {
            if (e[3] == 1) {
                if (!init_dsu.unite(e[0], e[1])) {
                    return -1;
                }
                max_must_s = min(max_must_s, (long long)e[2]);
            }
        }
        
        DSU full_dsu(n);
        int full_comps = n;
        for (const auto& e : edges) {
            if (full_dsu.unite(e[0], e[1])) full_comps--;
        }
        if (full_comps > 1) return -1;
        
        long long low = 1, high = min((long long)2e5, max_must_s);
        long long ans = -1;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, n, edges, k)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};