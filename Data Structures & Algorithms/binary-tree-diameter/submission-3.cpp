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
    // Use best as a global variable and helper function height to recursively call the height
    // because the longest path can bend at any node
    int best=0;
    int height(TreeNode* root) {
        if (root == nullptr) return 0; // Base case: Return 0 if nullptr.

        // Take the height of both left and right
        int left = height(root->left);
        int right = height(root->right);

        // Recursive case: update best based on the height of sum left right, otherwise keep best
        best = max(best, left + right);
        return 1 + max(left, right); // Needs to update left or right otherwise max(0,0) = 0
    }

    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return best;
    }
};
