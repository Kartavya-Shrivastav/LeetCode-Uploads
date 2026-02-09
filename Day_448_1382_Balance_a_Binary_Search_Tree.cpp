#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Problem: Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
// Approach: We can perform an inorder traversal of the given BST to get the node values in sorted order. Then, we can use the sorted array to construct a balanced BST by recursively selecting the middle element as the root and building the left and right subtrees from the left and right halves of the array, respectively.

// Steps:
// 1. Perform an inorder traversal of the given BST and store the node values in a vector.
// 2. Use the sorted array to construct a balanced BST by recursively selecting the middle element as the root and building the left and right subtrees from the left and right halves of the array, respectively.
// 3. Return the root of the balanced BST.

// Time Complexity: O(n), where n is the number of nodes in the BST. The inorder traversal takes O(n) time, and constructing the balanced BST also takes O(n) time. 
// Space Complexity: O(n), where n is the number of nodes in the BST. The space used to store the sorted array is O(n), and the space used by the recursive calls is O(log n) in the average case and O(n) in the worst case (when the tree is skewed). 
class Solution {
public:
    vector<TreeNode*> sortedArr;
    TreeNode* balanceBST(TreeNode* root) {
        inorderTraverse(root);
        return sortedArrayToBST(0, sortedArr.size() - 1);
    }
    void inorderTraverse(TreeNode* root) {
        if (root == NULL) return;
        inorderTraverse(root->left);
        sortedArr.push_back(root);
        inorderTraverse(root->right);
    }
    TreeNode* sortedArrayToBST(int start, int end) {
        if (start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode* root = sortedArr[mid];
        root->left = sortedArrayToBST(start, mid - 1);
        root->right = sortedArrayToBST(mid + 1, end);
        return root;
    }
};
