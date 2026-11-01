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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> waiting; waiting.push(root); // Push the root into the queue (BFS)
        while (!waiting.empty()) {
            int levelSize = waiting.size();

            for (int count=0; count<levelSize; count++) {
                TreeNode* current = waiting.front();
                waiting.pop();

                if (count == levelSize - 1) result.push_back(current->val); // This is because we push right side last in this code

                // Traversing method: Using two ifs so we can check and also move along the left and right side
                if (current->left != nullptr) waiting.push(current->left);
                if (current->right != nullptr) waiting.push(current->right);
            }
        }

        return result;
    }
};
