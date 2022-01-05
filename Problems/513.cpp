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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qu;
        qu.push(root);
        int val;
        while(qu.size() != 0) {
            int size = qu.size();
            val = qu.front()->val;
            for (int i = 0; i < size; ++i) {
                if (qu.front()->left) {
                    qu.push(qu.front()->left);
                }
                if (qu.front()->right) {
                    qu.push(qu.front()->right);
                }
                qu.pop();
            }
        }
        return val;
    }
};