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
    int ans=0;
    int goodNodes(TreeNode* root) {
        findGoodNodes(root, root->val);

        return ans;
    }

    void findGoodNodes(TreeNode* node, int maxNum){
        if(node==nullptr) return;

        if(maxNum <= node->val){
            ans++;
            maxNum = node->val;
        }

        findGoodNodes(node->left, maxNum);
        findGoodNodes(node->right, maxNum);
    }
};