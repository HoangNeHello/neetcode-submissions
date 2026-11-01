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
    bool validating(TreeNode* node, int low, int high) {
        if (node == nullptr) return true;

        if (low >= node->val || high <= node->val) return false; // Outside of (low, high) scope

        return validating(node->left, low, node->val) && validating(node->right, node->val , high); // Low is always low, so keep low in left. Same for right.
    }

    bool isValidBST(TreeNode* root) {
        return validating(root, INT_MIN, INT_MAX);
    }
};
