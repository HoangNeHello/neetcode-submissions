class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        // Run through the rows and columns
        for (int row=0; row<board.size(); row++) {
            for (int col=0; col<board[row].size(); col++) {
                if (dfs(board, word, row, col, 0)) return true;
            }
        }

        return false; // If the loop above fails
    }

    bool dfs(vector<vector<char>>& board, const string& word, int row, int col, int k) {
        // Stop (true)
        if (k == word.size()) return true; // Matched

        // Stop (false)
        if (row < 0 || col < 0 || row >= board.size() || col >= board[row].size()) return false; // Limit check
        if (board[row][col] != word[k]) return false; 

        // Choose: Save the letter and mark the cell
        if (board[row][col] == word[k]) board[row][col] = '#';

        // Recurse to four neighbours
        if(dfs(board, word, row+1, col, k+1)) return true;
        if (dfs(board, word, row-1, col, k+1)) return true;
        if (dfs(board, word, row, col+1, k+1)) return true;
        if (dfs(board, word, row, col-1, k+1)) return true;

        // Restore the letter
        board[row][col] = word[k]; // If the cell is the letter, then we can restore them like this

        return false; // None of the directions work
    }
};
