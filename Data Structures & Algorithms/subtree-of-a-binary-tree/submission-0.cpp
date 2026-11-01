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
    bool isSameTree(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) return true; // Reach the end without false statement
        if (root1 == nullptr || root2 == nullptr) return false; // Wrong structure
        if (root1->val != root2->val) return false; // Mismatch value (Value MUST be scanned last)

        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right); // The tree must match tightly, thus &&
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) return false; // Running out of nodes but still cannot find the match

        if (isSameTree(root, subRoot)) return true; // Check the root based on subRoot

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot); // Traversing left or right of the root, it doesn't matter for subRoot to not equal to right node or left node, so we use ||
    }
};
