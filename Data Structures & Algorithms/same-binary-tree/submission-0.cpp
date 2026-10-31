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
    bool isSameTree(TreeNode* p, TreeNode* q) { // Order matters
        if (p == nullptr && q == nullptr) return true; // Both are nullptr
        if (p == nullptr || q == nullptr) return false; // One of them is nullptr
        if (p->val != q->val) return false; // The val differs

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
