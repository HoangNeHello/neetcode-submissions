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
    int result = INT_MIN; // Start at negative infinity, so that tree with only 1 node is itself

    int sumUp(TreeNode* node) {
        if (node==nullptr) return 0; // Base case

        // If negative, turn into 0
        int left = max(0, sumUp(node->left));
        int right = max(0, sumUp(node->right));

        result = max(result, node->val + left + right);

        // Can only bend once, so we choose the best out of them
        return node->val + max(left, right); 
    }

    int maxPathSum(TreeNode* root) {
        sumUp(root);
        return result;
    }
};
