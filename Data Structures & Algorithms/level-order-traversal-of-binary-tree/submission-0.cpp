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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> nums;
        vector<vector<int>> ans;
        nums.push(root);

        while(!nums.empty()){
            int q_size = nums.size();
            vector<int> values;
            for(int i=0; i<q_size; i++){
                TreeNode* node = nums.front();

                values.push_back(node->val);
                if(node->left != nullptr) nums.push(node->left);
                if(node->right != nullptr) nums.push(node->right);

                nums.pop();
            }
            ans.push_back(values);
        }

        return ans;
    }
};