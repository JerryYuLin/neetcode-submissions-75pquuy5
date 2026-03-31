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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode *node = root;

        invertNode(node);
        
        return root;
    }

    void invertNode(TreeNode *node){
        if(node == nullptr) return;

        TreeNode *temp = node->left;
        node->left = node->right;
        node->right = temp;

        if(node->left != nullptr) invertNode(node->left);
        if(node->right !=nullptr) invertNode(node->right);
    }
};
