#include <bits/stdc++.h>
using namespace std;    

/*
Problem: Given the root of a binary tree, return the sum of all root-to-leaf binary numbers. The value of a node in the binary tree can only be 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit. For example, if the path is 0 -> 1 -> 1, then this could represent 011 in binary, which is 3 in decimal.
Approach: We can use a depth-first search (DFS) approach to traverse the binary tree. As we traverse the tree, we can keep track of the current binary number formed by the path from the root to the current node. When we reach a leaf node, we can add the current binary number to our total sum.

Steps:
1. Define a helper function dfs that takes a node and the current binary number formed so far.
2. If the node is null, return 0 (base case).
3. Update the current binary number by shifting the previous value to the left and adding the current node's value (curr = curr * 2 + node->val).
4. If the node is a leaf (no left and right children), return the current binary number.
5. Recursively call dfs for the left and right children and return the sum of their results.    

Time Complexity: O(n) where n is the number of nodes in the binary tree, since we need to visit each node once. 
Space Complexity: O(h) where h is the height of the binary tree, due to the recursive call stack. In the worst case (skewed tree), this could be O(n).
*/

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int curr) {
        if (!node) return 0;

        curr = curr * 2 + node->val; // append this bit

        if (!node->left && !node->right) // leaf
            return curr;

        return dfs(node->left, curr) + dfs(node->right, curr);
    }
};