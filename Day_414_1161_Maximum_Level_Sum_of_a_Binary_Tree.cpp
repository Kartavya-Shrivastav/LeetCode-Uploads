#include <bits/stdc++.h>
using namespace std;

// Problem: 1161. Maximum Level Sum of a Binary Tree
// Approach: We perform a depth-first search (DFS) traversal of the binary tree, keeping track of the sum of node values at each level. We use a vector to store the sums for each level. After the traversal, we find the maximum sum and return the corresponding level index.

// Steps:
// 1. Initialize a vector to store the sum of values at each level, starting with INT_MIN to handle negative values.
// 2. Define a recursive DFS function that takes a node and the current level as parameters.
//    - If the node is null, return.
//    - If the current level is equal to the size of the sum vector, it means we are visiting this level for the first time, so we add the node's value to the vector.
//    - Otherwise, we add the node's value to the existing sum for that level.
//    - Recursively call the DFS function for the left and right children, incrementing the level by 1.
// 3. After the DFS traversal, use the `max_element` function to find the maximum sum in the vector and return its index.

// Time Complexity: O(n), where n is the number of nodes in the binary tree, as we visit each node exactly once.    
// Space Complexity: O(h), where h is the height of the binary tree, due to

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> sum={INT_MIN};
    void dfs(TreeNode* Node, int level=1){
        if (Node==NULL) return;
        if (sum.size()==level) sum.push_back(Node->val);
        else sum[level]+=Node->val;
        dfs(Node->left, level+1);
        dfs(Node->right, level+1);
    }
    int maxLevelSum(TreeNode* root) {
        dfs(root);
        return max_element(sum.begin(), sum.end())-sum.begin();
        
    }
};