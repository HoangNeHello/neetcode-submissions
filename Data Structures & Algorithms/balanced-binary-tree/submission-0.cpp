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
    bool balanced = true;

    int height(TreeNode* root) {
        // Base case
        if (root == nullptr) return 0;

        int left = height(root->left);
        int right = height(root->right);

        if (left > right+1 || right > left+1) balanced = false; // Differ more than 1 node
        
        // Return 1+ so left or right can continue traverse
        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {
        height(root);
        return balanced;
    }
};
