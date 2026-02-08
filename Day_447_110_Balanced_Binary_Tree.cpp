
class Solution {
public:

    int height(TreeNode* node){
        if(node == nullptr) return 0;
        return (1 + max(height(node->left), height(node->right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;

        int height_l = height(root->left);
        int height_r = height(root->right);

        return (abs(height_l - height_r) <= 1 &&  isBalanced(root->left) && isBalanced(root->right));

        return 0;
    }
};