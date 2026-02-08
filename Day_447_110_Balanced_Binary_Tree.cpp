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