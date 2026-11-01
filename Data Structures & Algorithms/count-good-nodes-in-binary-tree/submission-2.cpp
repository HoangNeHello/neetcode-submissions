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
    int countGood(TreeNode* node, int maxSoFar) { // maxSoFar = biggest value on the path from root to here, passed down from the parent
        if (node == nullptr) return 0;

        int good = 0;
        if (node->val >= maxSoFar) good = 1;

        int newMax = max(maxSoFar, node->val);

        return good + countGood(node->left, newMax) + countGood(node->right, newMax); // Recurses to the last node to calculate each child
    }

    int goodNodes(TreeNode* root) { // The main one should be calling so it can start as the root
        if (root == nullptr) return 0;
        return countGood(root, root->val);
    }
};
