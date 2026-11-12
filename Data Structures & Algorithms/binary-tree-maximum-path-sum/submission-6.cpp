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
    int result = INT_MIN; // In case the root is negative

    int sumUp(TreeNode* node) {
        if (node == nullptr) return 0;

        int left = max(0, sumUp(node->left)); // Traversing, and also the negative is turned to 0
        int right = max(0, sumUp(node->right));

        result = max(result, node->val + left + right);

        return node->val + max(left, right); // Only bend on one side, either left or right. Choose max, because we want the positive node value.
    }

    int maxPathSum(TreeNode* root) {
        sumUp(root);
        return result;
    }
};
