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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> que1, que2;
        if (root) {
            que1.push(root);
            que2.push(root);
        }
        bool f = true;
        while (f) {
            int size = que1.size();
            f = false;
            for (int i = 0; i < size; ++i) {
                if (que1.front() == nullptr && que2.front() != nullptr) {
                    return false;
                } else if (que2.front() == nullptr && que1.front() != nullptr) {
                    return false;
                } else if (que1.front() != nullptr && que2.front() != nullptr && 
                           que1.front()->val != que2.front()->val) {
                    return false;
                }
                if (que1.front() && (que1.front()->left || que1.front()->right)) {
                    f = true;
                }
                if (que2.front() && (que2.front()->left || que2.front()->right)) {
                    f = true;
                }
                if (que1.front()) {
                    que1.push(que1.front()->left);
                    que1.push(que1.front()->right);
                } 
                if (que2.front()) {
                    que2.push(que2.front()->right);
                    que2.push(que2.front()->left);
                }
                que1.pop();
                que2.pop();
            }
        }
        return true;
    }
};

class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left && right || left && !right) {
            return false;
        }
        if (left && right && left->val != right->val) {
            return false;
        }
        if (!left && !right) {
            return true;
        }
        bool outside = helper(left->left, right->right);
        bool inside = helper(left->right, right->left);
        return outside && inside;
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) {
            return true;
        }
        return helper(root->left, root->right);
    }
};