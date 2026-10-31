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
    int best=0;
    int height(TreeNode* root) {
        if (root == nullptr) return 0; // Base case: Return 0 if nullptr.

        // Return the height of both left and right
        int left = height(root->left);
        int right = height(root->right);

        // Recursive case: update best based on the height of sum left right
        best = max(best, left + right);
        return 1 + max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;
    }
};
