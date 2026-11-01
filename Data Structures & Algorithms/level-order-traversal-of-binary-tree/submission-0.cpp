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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result; // If there's nothing else return result

        queue<TreeNode*> waiting;
        waiting.push(root);

        while (!waiting.empty()) {
            int levelSize = waiting.size();
            vector<int> level;

            for (int count = 0; count < levelSize; count++) {
                TreeNode* current = waiting.front();
                waiting.pop();

                level.push_back(current->val);

                if (current->left != nullptr) waiting.push(current->left); // Add if there exists on left
                if (current->right != nullptr) waiting.push(current->right); // Add if there exists on right
            }

            result.push_back(level);
        }

        return result;
    }
};
