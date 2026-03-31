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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i=0; i<inorder.size();i++){
            inorder_map[inorder[i]] = i;
        }

        return constructTree(
            preorder,
            0,
            preorder.size()-1,
            inorder,
            0,
            inorder.size()-1,
            inorder_map
        );
    }

    TreeNode* constructTree(
        vector<int>& preorder,
        int pre_start,
        int pre_end,
        vector<int>& inorder,
        int in_start,
        int in_end,
        unordered_map<int, int>& inorder_map
    ) {
        if (pre_start > pre_end || in_start > in_end) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[pre_start]);
        
        int k = inorder_map[node->val];

        int left_subtree_size = k - in_start;

        node->left = constructTree(
            preorder,
            pre_start + 1,
            pre_start + left_subtree_size,
            inorder,
            in_start,
            k - 1,
            inorder_map
        );

        node->right = constructTree(
            preorder,
            pre_start + left_subtree_size + 1,
            pre_end,
            inorder,
            k + 1,
            in_end,
            inorder_map
        );

        return node;
    }
};