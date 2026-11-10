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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "#";

        string result;

        // Preorder
        
        string left = serialize(root->left);
        string right = serialize(root->right);
        result = to_string(root->val) + "," + left + "," + right;

        return result;
    }

    // Helper function
    TreeNode* buildTree(queue<string>& tokens) {
        string t = tokens.front();
        tokens.pop();

        if (t == "#") return nullptr; // # indicates nullptr

        TreeNode* node = new TreeNode(stoi(t)); // Build the tree phase
        node->left = buildTree(tokens);
        node->right = buildTree(tokens);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // Putting each of the string into the queue
        queue<string> tokens;
        stringstream ss(data);
        string t;
        while (getline(ss, t, ',')) tokens.push(t);


        // Build the tree
        return buildTree(tokens);
    }
};
