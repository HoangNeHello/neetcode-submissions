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
    int maxDepth(TreeNode* root) { // BFS
        if (root==nullptr) return 0;
        
        queue<TreeNode*> waiting; waiting.push(root);
        int depth=0;
        while (!waiting.empty()) {
            int levelSize = waiting.size();
            for (int count=0; count < levelSize; count++) {
                TreeNode* node = waiting.front();
                waiting.pop();

                if (node->left) waiting.push(node->left);
                if (node->right) waiting.push(node->right);
            }
            depth++;
        }

        return depth;
    }
};
