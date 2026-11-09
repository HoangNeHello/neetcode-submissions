class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> LCS(n+1, vector<int>(m+1)); // Fill out 0 -> Base case automatically

        // Start at 1 because at "" there's nothing to compare
        for (int row=1; row<=n; row++) {
            for (int col=1; col<=m; col++) {
                if (text1[row-1] == text2[col-1]) {
                    LCS[row][col] = LCS[row-1][col-1] + 1;
                } else {
                    LCS[row][col] = max(LCS[row-1][col], LCS[row][col-1]);
                }
            }
        }

        return LCS[n][m];
    }
};
