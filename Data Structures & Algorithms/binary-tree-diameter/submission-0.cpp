/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int max_diameter = 0;

    int diameterOfBinaryTree(TreeNode* root) {
        maxDepth(root);

        return max_diameter;
    }

    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left_depth = 0, right_depth=0;
        
        if(root->left) left_depth = 1 + maxDepth(root->left);
        if(root->right) right_depth = 1 + maxDepth(root->right);

        int diameter = left_depth + right_depth;

        max_diameter = max(diameter, max_diameter);

        return max(left_depth, right_depth);
    }
};