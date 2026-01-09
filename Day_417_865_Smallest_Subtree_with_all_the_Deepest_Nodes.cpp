#include <bits/stdc++.h>
using namespace std;

// Problem: 865. Smallest Subtree with all the Deepest Nodes
// Approach: We perform a BFS to find the deepest nodes and then move upwards to find their lowest common ancestor.

// Steps:
// 1. Use a queue to perform a level-order traversal (BFS) of the tree, keeping track of parent nodes.
// 2. Store the nodes at the last level of the tree.
// 3. Use a set to keep track of the deepest nodes.
// 4. Move upwards from these deepest nodes using the parent mapping until only one node remains in the set.
// 5. Return that node as the result.

// Time Complexity: O(n), where n is the number of nodes in the tree, as we visit each node once.
// Space Complexity: O(n) for storing the parent mapping and the queue.

class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root) return nullptr;

        unordered_map<TreeNode*, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = nullptr;

        vector<TreeNode*> lastLevel;

        // BFS traversal
        while (!q.empty()) {
            int size = q.size();
            lastLevel.clear();

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                lastLevel.push_back(node);

                if (node->left) {
                    parent[node->left] = node;
                    q.push(node->left);
                }
                if (node->right) {
                    parent[node->right] = node;
                    q.push(node->right);
                }
            }
        }

        unordered_set<TreeNode*> deepest(lastLevel.begin(), lastLevel.end());

        // Move upward until one node remains
        while (deepest.size() > 1) {
            unordered_set<TreeNode*> next;
            for (auto node : deepest) {
                next.insert(parent[node]);
            }
            deepest = next;
        }

        return *deepest.begin();
    }
};