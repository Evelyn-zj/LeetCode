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
        queue<TreeNode*> que;
        vector<vector<int>> order;
        if (root != nullptr) {
            que.push(root);
        }
        while (que.size() != 0) {
            vector<int> temp;
            int size = que.size();
            for (int i = 0; i < size; ++i) {
                temp.push_back(que.front()->val);
                if (que.front()->left) {
                    que.push(que.front()->left);
                }
                if (que.front()->right) {
                    que.push(que.front()->right);
                }
                que.pop();
            }
            order.push_back(temp);
        }
        return order;
    }
};