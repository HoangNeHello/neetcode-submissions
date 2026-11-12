class PrefixTree {
public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';

            // If there's no new children, add them
            if (curr->children[index] == nullptr) curr->children[index] = new TrieNode();

            // Traverse like a linked list
            curr = curr->children[index];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int index = c - 'a';

            // If it ends but not at the last word, return false
            if (curr->children[index] == nullptr) return false;

            curr = curr->children[index];
        }

        return curr->isEnd; // Return the state of the last word to confirm it is added
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int index = c - 'a';

            if (curr->children[index] == nullptr) return false;

            curr = curr->children[index];
        }

        return true; // Everything survives
    }

private:
    struct TrieNode {
        TrieNode* children[26] = {}; // All the alphabets
        bool isEnd = false;          // True if the word ends at this node
    };

    TrieNode* root;
};
