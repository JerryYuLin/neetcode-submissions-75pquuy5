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
    bool found = false;

    bool isBalanced(TreeNode* root) {
        maxDepth(root);

        return !found;
    }

    int maxDepth(TreeNode* node){
        if(node == nullptr || found) return 0;

        int leftDepth = 1 + maxDepth(node->left);
        int rightDepth = 1 + maxDepth(node->right);

        if(abs(leftDepth-rightDepth) > 1) {
            found = true;
        }

        return max(leftDepth, rightDepth);
    }
};
