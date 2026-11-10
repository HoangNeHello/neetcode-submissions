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
    TreeNode* invertTree(TreeNode* root) { // BFS
        // Base case
        if (root == nullptr) return root;

        queue<TreeNode*> waiting; waiting.push(root);

        while (!waiting.empty()) {
            // Basic queue moving
            TreeNode* node = waiting.front();
            waiting.pop();

            // Traversing method
            invertTree(node->left);
            invertTree(node->right);

            // Rewiring
            swap(node->left, node->right);
        }

        return root;
    }
};
