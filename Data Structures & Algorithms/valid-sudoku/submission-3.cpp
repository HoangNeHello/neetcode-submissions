class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // We will use this to check for rows, columns, and each 3x3 box to see if the value is repeated or not (using set here is more efficient than map)
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> boxes(9);

        for (int row=0; row<9; row++) {
            for (int col=0; col<9; col++) {
                char val = board[row][col];

                if (val == '.') continue; // Skip the .

                int box_index = (row/3)*3 + col/3; // This is to check the 3x3 block each iteration

                if (boxes[box_index].count(val) || rows[row].count(val) || cols[col].count(val)) {
                    return false; // If there appears to be another value, return false
                }

                // If not, add it to the set
                boxes[box_index].insert(val);
                rows[row].insert(val);
                cols[col].insert(val);

            }
        }
        return true; // If nothing happens, return true
    }
};
