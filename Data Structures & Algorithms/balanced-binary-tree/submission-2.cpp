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

    // Use -1 as an indicator of the imbalance
    int height(TreeNode* root) {
        // Base case
        if (root == nullptr) return 0;

        int left = height(root->left);
        if (left == -1) return -1;

        int right = height(root->right);
        if (right == -1) return -1;

        if (left > right+1 || right > left+1) return -1; // Differ more than 1 node
        
        // Return 1+ because we are moving upward from the last child. Without 1+, all heights are 0, the imbalance cannot be detected
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};
