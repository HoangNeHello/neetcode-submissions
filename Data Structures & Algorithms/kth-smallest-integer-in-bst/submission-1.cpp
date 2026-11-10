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
//   count  = how many nodes we've visited so far (in sorted order)
//   kth    = the target k, stored so visit() can see it
//   result = where the answer lands, because visit() and inorder()
//            are void and can't return it
    int count = 0;
    int kth = 0;
    int result = 0;

    void inorder(TreeNode* node) {
        if (node==nullptr) return;

        inorder(node->left);    // 1. everything smaller
        count++;                                // one more node seen, in ascending order
        if (count == kth) result = node->val;   // this is the k-th smallest
        inorder(node->right);   // 3. everything bigger
    }

    int kthSmallest(TreeNode* root, int k) {
        kth = k;          // pass k on to visit()
        inorder(root);    // walk the whole tree; visit() fills result
        return result;    // read the answer visit() left behind
    }
};
