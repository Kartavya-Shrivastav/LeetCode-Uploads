#include <bits/stdc++.h>
using namespace std;

// Problem: 1339. Maximum Product of Splitted Binary Tree
// Approach: We first calculate the total sum of all nodes in the binary tree. Then, we perform a post-order traversal to compute the sum of each subtree. For each subtree sum, we calculate the product of that sum and the complement (total sum - subtree sum) and keep track of the maximum product found.

// Steps:
// 1. Define a function `totalSum` to calculate the total sum of the binary tree.
// 2. Define a recursive function `subTreeSum` that computes the sum of each subtree and updates the maximum product.
// 3. In `maxProduct`, first call `totalSum` to get the total sum, then call `subTreeSum` to find the maximum product.
// 4. Return the maximum product modulo 10^9 + 7.

// Time Complexity: O(n), where n is the number of nodes in the binary tree, as we visit each node a constant number of times.    
// Space Complexity: O(h), where h is the height of the binary tree, due to the recursion stack.

class Solution {
public:
long long mod = 1e9 + 7;
long long total = 0;
long long ans = 0;

    long long subTreeSum(TreeNode* root) {
        if(root == NULL)    return 0;

        long long leftSum = subTreeSum(root->left);
        long long rightSum = subTreeSum(root->right);

        ans = max(ans, (leftSum * (total - leftSum)));
        ans = max(ans, (rightSum * (total - rightSum)));

        return leftSum + rightSum + root->val;
    }

    void totalSum(TreeNode* root) {
        if(root == NULL)    return;
        total += root->val;
        totalSum(root->left);
        totalSum(root->right);
    }

    int maxProduct(TreeNode* root) {
        totalSum(root);
        subTreeSum(root);
        return ans % mod;
    }
};