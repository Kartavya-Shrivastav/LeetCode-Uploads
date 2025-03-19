#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> parent;
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        parent.resize(1010);
        for (int i = 0; i < parent.size(); ++i)
            parent[i] = i;

        for (auto& edge : edges) {
            int nodeA = edge[0], nodeB = edge[1];
            if (find(nodeA) == find(nodeB)) return edge;
            parent[find(nodeA)] = find(nodeB);
        }
        return {};
    }
    
    int find(int node) {
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    }
};