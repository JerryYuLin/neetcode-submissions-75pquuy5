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
    bool isValidBST(TreeNode* root) {

        stack<tuple<TreeNode*, long long, long long>> node_tuples;
        node_tuples.emplace(root, LONG_MIN, LONG_MAX);

        while(!node_tuples.empty()){
            TreeNode* node = get<0>(node_tuples.top());
            long long minBoundary = get<1>(node_tuples.top());
            long long maxBoundary = get<2>(node_tuples.top());
            node_tuples.pop();

            if(node->left != nullptr) {
                long long maxB = node->val < maxBoundary ? node->val : maxBoundary;
                if(node->left->val < maxB && node->left->val > minBoundary){
                    node_tuples.emplace(node->left, minBoundary, maxB);
                }
                else return false;
            }

            if(node->right != nullptr) {
                long long minB = node->val > minBoundary ? node->val : minBoundary;
                if(node->right->val > minB && node->right->val < maxBoundary){
                    node_tuples.emplace(node->right, minB, maxBoundary);
                }
                else return false;
            }
        }

        return true;
    }
};