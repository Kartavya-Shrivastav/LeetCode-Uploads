#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given a binary tree, determine if it is height-balanced. A binary tree is height-balanced if for every node in the tree, the difference in height between its left and right subtrees is at most 1.
// Approach: We can use a recursive approach to check if the tree is balanced. For each node, we will calculate the height of its left and right subtrees and check if the difference in height is at most 1. We will also recursively check if the left and right subtrees are balanced.

// Steps:
// 1. Define a helper function to calculate the height of a subtree.
// 2. In the main function, for each node, calculate the height of its left and right subtrees.
// 3. Check if the absolute difference in height is at most 1 and recursively check if the left and right subtrees are balanced.
// 4. Return true if the tree is balanced, otherwise return false.

// Time Complexity: O(N^2) in the worst case, where N is the number of nodes in the tree, because for each node we are calculating the height of its subtrees which takes O(N) time.
// Space Complexity: O(H), where H is the height of the tree, due to the recursive call stack. In the worst case of a skewed tree, this can be O(N).

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

    int height(TreeNode* node){
        if(node == nullptr) return 0;
        return (1 + max(height(node->left), height(node->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;

        int height_l = height(root->left);
        int height_r = height(root->right);

        return (abs(height_l - height_r) <= 1 &&  isBalanced(root->left) && isBalanced(root->right));
    }
};