class Solution {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word; // To let dfs know which word to push
    };

    TrieNode* root;

public:
    Solution() {
        root = new TrieNode();
    }

    void dfs(TrieNode* node, vector<vector<char>>& board, int row, int col, vector<string>& result) {
        // Out of bound
        if (row < 0 || col < 0) return;
        if (row >= board.size() || col >= board[row].size()) return;
        
        if (board[row][col] == '#') return; // Already used 

        // Read the cell's character and step into its trie child
        char c = board[row][col];
        node = node->children[c-'a'];
        if (node == nullptr) return; // No word continues with this letter
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = "";
        }

        // Mark the cell as used
        board[row][col] = '#';
        
        // Recurse to 4 neighbours
        dfs(node, board, row-1, col, result);
        dfs(node, board, row+1, col, result);
        dfs(node, board, row, col+1, result);
        dfs(node, board, row, col-1, result);

        // Unmark the cell, so it can be reused
        board[row][col] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i=0; i<words.size(); i++) {
            insertWord(words[i]);
        }

        vector<string> result;

        for (int row=0; row<board.size(); row++) {
            for (int col=0; col<board[row].size(); col++) {
                dfs(root, board, row, col, result); // Start a search
            }
        }

        return result;
    }

    // Adding to trie nodes method
    void insertWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';
            if (curr->children[index] == nullptr) curr->children[index] = new TrieNode();
            curr = curr->children[index]; 
        }
        curr->word = word;
    }
};
