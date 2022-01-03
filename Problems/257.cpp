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
    void searchPath(TreeNode* node, string path, vector<string>& allPath) {
        path += to_string(node->val);
        if (!node->left && !node->right) {
            allPath.push_back(path);
            return;
        }
        if (node->left) {
            searchPath(node->left, path + "->", allPath);
        }
        if (node->right) {
            searchPath(node->right, path + "->", allPath);
        }
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> allPath;
        if (!root) {
            return allPath;
        }
        string path = "";
        searchPath(root, path, allPath);
        return allPath;
    }
};