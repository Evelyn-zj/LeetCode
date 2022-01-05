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
    bool path(TreeNode* root, int targetSum) {
        if (!root->left && !root->right) {
            if (targetSum == root->val) {
                return true;
            } else {
                return false;
            }
        }
        bool left = false, right = false;
        if (root->left) {
            left = hasPathSum(root->left, targetSum - root->val);
        }
        if (root->right) {
            right = hasPathSum(root->right, targetSum - root->val);
        }
        return left | right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        return path(root, targetSum);
    }
};