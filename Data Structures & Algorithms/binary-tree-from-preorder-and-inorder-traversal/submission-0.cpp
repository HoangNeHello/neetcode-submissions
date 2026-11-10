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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Base case
        if (preorder.size()==0 || inorder.size()==0) {
            return nullptr;
        }

        int root = preorder[0]; // In preorder, the root is the fist element

        // Find the left and right. LEFT - root - RIGHT Inorder
        int mid = 0;
        for (int i=0; i<inorder.size(); i++) {
            if (root == inorder[i]) {
                mid = i; // Find the root inside inorder
            }
        }
        vector<int> leftIn(inorder.begin(), inorder.begin()+mid);
        vector<int> rightIn(inorder.begin()+mid+1, inorder.end());

        // Reusing the mid because it's the same position, but different separation
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+mid+1);
        vector<int> rightPre(preorder.begin()+mid+1, preorder.end());

        TreeNode* node = new TreeNode(root);
        node->left = buildTree(leftPre, leftIn);
        node->right = buildTree(rightPre, rightIn);

        return node;
    }
};
