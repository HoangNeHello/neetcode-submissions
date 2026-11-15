class WordDictionary {
private:
    struct TrieNode {
        TrieNode* children[26] = {};
        bool isEnd = false;
    };

    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) curr->children[index] = new TrieNode();

            curr = curr->children[index];
        }

        curr->isEnd = true;
    } 
    
    bool dfs(TrieNode* node, const string& word, int i) { // Because they accept . 
        // Base case
        if (i == word.size()) return node->isEnd; // Ran through the word -> exists

        if (word[i] == '.') {
            for (int j=0; j<26; j++) {
                if (node->children[j] != nullptr && dfs(node->children[j], word, i+1)) return true;
            }
            return false;
        }

        int index = word[i] - 'a';

        if (node->children[index] == nullptr) return false;
        else {
            return dfs(node->children[index], word, i + 1);
        }
    }

    bool search(string word) {
        TrieNode* curr = root;
        return dfs(curr, word, 0);
    }
};
