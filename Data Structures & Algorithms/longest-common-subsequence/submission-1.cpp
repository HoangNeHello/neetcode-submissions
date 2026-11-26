class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) { // O(rxc)
        int n = text1.size(), m = text2.size();
        vector<vector<int>> table(n+1, vector<int>(m+1)); // Construct the table

        // Only -1 for col and row because we track the PREVIOUS neighbour cell
        for(int row=1; row<=n; row++) {
            for (int col=1; col<=m; col++) {
                if (text1[row-1] == text2[col-1]) { // Increase by 1 from the neighbour cell
                    table[row][col] = table[row-1][col-1] + 1; 
                } else { // Otherwise, keep that value
                    table[row][col] = max(table[row-1][col], table[row][col-1]);
                }
            }
        }

        return table[n][m]; // The last cell is the answer
    }
};
